#include <bits/stdc++.h>
using namespace std;

class Telephone{
   public:
   struct client{
       string number;
       bool isoccupied;
  
    client() : isoccupied(false) {}
    client(string p) : number(p),isoccupied(true) {}
   };


   vector<client> table;
   int tables;


   Telephone(int size): tables(size),table(size) {}


   int hasht(string key){
       long int k=stol(key);
       int last=k%10;
       return last;
   }


   int withreplacement(string number){
       int idx=hasht(number);
       int cmp=0;
      


        if(table[idx].isoccupied && (stol(table[idx].number)%10!=idx)){
           string emp=table[idx].number;
           table[idx].number=number;
           cmp++;
           while(table[idx].isoccupied){
               idx=(idx+1)%tables;
               cmp++;
           }
           table[idx]=client(emp);
        }


        else{
           while(table[idx].isoccupied){
               idx=(idx+1 )%tables;
               cmp++;
           }
           table[idx]=client(number);


        }


        return cmp;


   }


   int withoutreplacement(string number){
       int idx=hasht(number);
       int cmp=0;


        while(table[idx].isoccupied){
           idx=(idx+1)%tables;
           cmp++;
          
        }


       
        table[idx]=client(number);


        return cmp;


   }


   string search(string number){
       int idx=hasht(number);
       int cmp=0;
       for(auto c:table){
           if(c.number==number){
               return "No. found!";
           }
       }


       return "Not Found";
   }
   void display() {
       for(int i=0;i<10;i++){
           if(table[i].isoccupied){
               cout<<"Phone: "<<table[i].number<<endl;
           }
           else{
               cout<<"Phone: "<<"NULL"<<endl;
           }
       }
   }
  


};


int main(){
   Telephone book(10);


   cout<<"Insert without replacement: "<<endl;
   int cmp=0;
  


   for(int i=0;i<6;i++){
       string n;
       cout<<"Enter the telephone number: "<<endl;
       cin>>n;
       cmp+=book.withoutreplacement(n);
   }
  
   book.display();
   cout<<"Total comparisons: "<<cmp<<endl<<endl;


   cout<<"Insert withreplacement: "<<endl;


   for(int i=0;i<3;i++){
       string n;
       cout<<"Enter no. to replace: "<<endl;
       cin>>n;
       cmp+=book.withreplacement(n);
   }


   book.display();
   cout<<"Total comparisons: "<<cmp<<endl<<endl;
   cout<<"Enter no. to search: ";
   string n;
   cin>>n;
   cout<<endl;
   cout<<"Searching for no. ";
   cout<<book.search(n);
  

}


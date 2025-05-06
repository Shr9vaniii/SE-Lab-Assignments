#include <bits/stdc++.h>
using namespace std;
class ll{
   public:
  string val;
  ll* next;


  ll(string x){
   val=x;
   next=NULL;
  }


};


void insert(ll* &head,string key){
   ll* n=new ll(key);
   if(!head){
     head=n;
     return;
   }
   ll* temp=head;
   while(temp->next!=NULL){
       temp=temp->next;
   }
   temp->next=n;
}


void prints(ll* head){
   if(head==NULL){
       cout<<"NULL"<<endl;
       return;
   }
   ll* temp=head;
   while(temp!=NULL){
       cout<<temp->val<<" -> ";
       temp=temp->next;
   }
   cout<<"NULL"<<endl;
  
}


int hashf(string s){
   int hash=(s[0]-'a')%26;
   return hash;
}


map<int,ll*> mp;


void inserts(string value){
   int hash=hashf(value);
   insert(mp[hash],value);
}


void print(){
   for (int i=0;i<26;i++){
       if(i>9){
           cout<<i<<"    ";
           prints(mp[i]);
       }
       else{
           cout<<i<<"     ";
           prints(mp[i]);
       }
      
   }
}


void find(int key){
if(mp[key]!=NULL) cout<<"Key found!"<<endl;
else cout<<"Key not found!"<<endl;
  
}


void deletes(int key){
    mp.erase(key);
}


int main(){
  
   for(int i=0;i<20;i++){
       string s;
       cout<<"Enter the string: ";
       cin>>s;
       inserts(s);
       cout<<"Value inserted!"<<endl;
   }


   cout<<endl;
   cout<<"The hash table is: "<<endl;
   print();


   cout<<"Find a key: ";
   int k;
   cin>>k;
   find(k);
   cout<<endl;
   cout<<"Delete key: ";
   int n;
   cin>>n;
   deletes(n);
   print();
}


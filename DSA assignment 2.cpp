# include <bits/stdc++.h>
using namespace std;


class tree{
public:
int data;
   tree* left;
   tree* right;
   tree(int x){
       data=x;
       left=right=nullptr;
   }
};


void insert(tree* &root,int key){
   tree* n=new tree(key);
   if(root==nullptr){
       root=n;
       return;
   }
   if(key==root->data) return;


   if(key>root->data){
       insert(root->right,key);
   }
   else if(key<root->data){
       insert(root->left,key);
   }
  
}


void inorder(tree* &root){
   if(root==nullptr) return;
  
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
  
}
void preorder(tree* &root){
   if(root==nullptr) return;
  
   cout<<root->data<<" ";


   preorder(root->left);
  
   preorder(root->right);
  
}


void postorder(tree* &root){
   if(root==nullptr) return;
  
  
   postorder(root->left);
  
   postorder(root->right);
   cout<<root->data<<" ";
  
}


bool search_key(tree* root,int k){


   if(root==nullptr) return false;
   if(k==root->data) return true;


   if(k<root->data){
       return search_key(root->left,k);
   }
   else{
       return search_key(root->right,k);
   }
  
}


pair<int,int> longest(tree* root){
   pair<int,int> p;
   if(root==nullptr){
       p=make_pair(0,0);
       return p;
   }
pair<int,int> l=longest(root->left);
pair<int,int> r=longest(root->right);


int lh=l.first;
int rh=r.first;
int he=l.second+r.second+1;


p=make_pair(max(lh,max(rh,he)),max(l.second,r.second)+1);
return p;
  
}


int longestpath(tree* root){
 return longest(root).first;


}


int mini(tree* root){
   if(root->left==nullptr) return root->data;


   return mini(root->left);
}


int maxi(tree* root){
   if(root->right==nullptr) return root->data;
   return maxi(root->right);
}


void swapnode(tree* &root){
   if(root==nullptr) return;


   swapnode(root->left);
   swapnode(root->right);


   tree* temp=root->left;
   root->left=root->right;
   root->right=temp;
}




int main(){
   tree* root=nullptr;
   insert(root,10);
   insert(root,4);
   insert(root,12);
   insert(root,14);
   insert(root,5);
   insert(root,3);
   insert(root,30);
   insert(root,7);
   cout<<"BST is: "<<endl;
   cout<<"Inorder:";
   inorder(root);
   cout<<endl;
   cout<<"Preorder: ";
   preorder(root);
   cout<<endl;
   cout<<"Postorder: ";
   postorder(root);
   cout<<endl;
   cout<<"Enter the key to be searched: "<<endl;
   int k;
   cin>>k;
   if(search_key(root,k)) cout<<"Element found!"<<endl;
   else cout<<"Element not found"<<endl;


   cout<<"Longest path is: "<<longestpath(root)<<endl;


   cout<<"Minimum value in BST is: "<<mini(root)<<endl;
   cout<<"Maximum value in BST is: "<<maxi(root)<<endl;
   cout<<"Swapped tree is: "<<endl;
   swapnode(root);
   inorder(root);
   cout<<endl;
}


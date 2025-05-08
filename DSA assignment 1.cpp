#include <bits/stdc++.h>
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


void insertnodeleft(tree* & root,int x){
   tree* n=new tree(x);
   root->left=n;
}
void insertright(tree* &root,int x){
   tree* n=new tree(x);
   root->right=n;
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


void iterinorder(tree* root){
   stack<tree*> st1;
   tree* temp=root;
  
   while(temp!=nullptr || !st1.empty()){
       while(temp!=nullptr){
           st1.push(temp);
           temp=temp->left;
       }


       temp=st1.top();
       st1.pop();
       cout<<temp->data<<" ";
       temp=temp->right;
   }
}


vector<int> preord(tree* root){
   stack<tree*> st;
   vector<int> arr;
   if(root==nullptr) return arr;


   st.push(root);
   while(!st.empty()){
      
       root=st.top();
       st.pop();
      
       arr.push_back(root->data);
      
      


       if(root->right!=nullptr) st.push(root->right);


       if(root->left!=nullptr) st.push(root->left);
   }


   return arr;

}
int count_leaf(tree* root){
  


   if(root==nullptr) return 0;


   if(root->left==nullptr && root->right==nullptr){
        
       return 1;
   }
  
  
   return count_leaf(root->left) + count_leaf(root->right);
}


void iterpost(tree* root){
   stack<tree*> st1;
   stack<tree*> st2;


   if(root==nullptr) return;
   st1.push(root);
   while(!st1.empty()){
       root=st1.top();
       st1.pop();
       st2.push(root);
        if(root->left!=nullptr) st1.push(root->left);
       if(root->right!=nullptr) st1.push(root->right);
   }


   while(!st2.empty()){
       cout<<st2.top()->data<<" ";
       st2.pop();
   }
   cout<<endl;
}


int height(tree* root){
   if(root==nullptr) return 0;
   if(root->left==nullptr && root->right==nullptr) return 1;
   int lefth=height(root->left);
   int righth=height(root->right);
   return max(lefth,righth) +1;
}


void mirror(tree* root,tree* &root1){


   if(root==nullptr) return;


   if(root->left!=nullptr){
      
       insertright(root1,root->left->data);
       mirror(root->left,root1->right);
   }
   if(root->right!=nullptr) {
       tree* r=root->right;
       insertnodeleft(root1,r->data);
       mirror(root->right,root1->left);
      
   }
  
}


int internal_nodes(tree* root,int cnt){
   if(root==nullptr) return cnt;
   ++cnt;
   cnt=internal_nodes(root->left,cnt);
   cnt=internal_nodes(root->right,cnt);
   return cnt;
}

void erase(tree* &root){
   if(root==nullptr){
      
       return;
   }
   erase(root->left);
   erase(root->right);
  
   root=nullptr;
   return;
}


void copy(tree* ori,tree* &dupli){
   if(ori==nullptr) return;
   if(ori->left!=nullptr){
       insertnodeleft(dupli,ori->left->data);
       copy(ori->left,dupli->left);
   }
   if(ori->right!=nullptr){
       insertright(dupli,ori->right->data);
       copy(ori->right,dupli->right);
   }
}


int main() {
   tree * root=new tree(1);
   insertnodeleft(root,2);
   insertright(root,3);
   insertnodeleft(root->left,4);
   insertright(root->left,5);
   insertnodeleft(root->right,6);
   insertright(root->right,7);
  
   cout<<"Inorder traversal:"<<" ";
   inorder(root);
   cout<<endl;
   cout<<"Preorder traversal:"<<" ";
   preorder(root);
   cout<<endl;
   cout<<"Postorder traversal:"<<" ";
   postorder(root);
   cout<<endl;
   cout<<"Iterative inorder: ";
   iterinorder(root);
   cout<<endl;
   cout<<"iterative preorder: ";
   vector<int> ans=preord(root);
   for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
   cout<<endl;
   cout<<"Iterative postorder: ";
   iterpost(root);
   cout<<endl;
   cout<<"leaf nodes are: "<<count_leaf(root);
  
   cout<<endl;
   cout<<"Height of tree is: "<<height(root)<<endl;
   tree* root1=new tree(root->data);
   mirror(root,root1);
   cout<<"Inorder of the mirror tree: ";
   iterinorder(root1);
   cout<<endl;
   int leaf=count_leaf(root);
   int i=internal_nodes(root,0);
   cout<<"No. of internal nodes are: "<<i-leaf-1<<endl;
   erase(root);
   cout<<"Tree is: "<<endl;
   iterinorder(root);
   cout<<endl;
   tree* dupli=new tree(root1->data);
   copy(root1,dupli);
   cout<<"Duplicated tree is: ";
   iterinorder(dupli);
   cout<<endl;
  
  
}








#include <bits/stdc++.h>
using namespace std;


class tree{
public:
   int data;
   tree* left;
   tree* right;
   bool lthread;
   bool rthread;


   tree(int x){
       data = x;
       left = right = nullptr;
       lthread = rthread = false;
   }
};


tree* insert(tree* &root, int key) {
   tree* ptr = root;
   tree* par = NULL;


  
   while (ptr != NULL) {
       if (key == ptr->data) {
           cout << "Duplicate key" << endl;
           return root;
       }
          


       par = ptr;
       if (key < ptr->data) {
           if (ptr->lthread == false)   ptr = ptr->left;
            
           else
               break;
       } else {
           if (ptr->rthread == false)
               ptr = ptr->right;
           else
               break;
       }
   }


   tree* temp = new tree(key);
   temp->lthread = true;
   temp->rthread = true;


 
   if (par == NULL) {
       root = temp;
   }
   else if (key < par->data) {
       temp->left = par->left;
       temp->right = par;
       par->lthread = false;
       par->left = temp;
   }
   else {
       temp->right = par->right;
       temp->left = par;
       par->rthread = false;
       par->right = temp;
   }
   return root;
}




tree* inordersuccesor(tree* ptr) {
   if(ptr==NULL) return NULL;
   if (ptr->rthread == true)
       return ptr->right;
  
   ptr = ptr->right;
   while (ptr->lthread == false)
       ptr = ptr->left;
  
   return ptr;
}


void inorder(tree* root) {
   if (root == NULL) return;


   tree* temp = root;


  
   while (temp->lthread == false) {
       temp = temp->left;
   }


  
   while (temp != NULL) {
       cout << temp->data << " ";
       temp = inordersuccesor(temp);
   }
   cout<<endl;
}


/*void preorder(tree* root) {
   if (root == NULL) return;


   tree* curr = root;
  
   while (curr != NULL) {
      
       cout << curr->data << " ";


      
       if (curr->lthread == false) {
           curr = curr->left;
       }
       else {
        
           if (curr->rthread == false) {
               curr = curr->right;
           }
           else {
              
               curr = NULL;
           }
       }
   }
   cout << endl;
}*/


void deleteLeafNode(tree* par, tree* ptr,tree* &root) {
   if (par == NULL) {
      
       root = NULL;
   } else {
       if (par->left == ptr) {
           par->lthread = true;
           par->left = ptr->left;
       } else {
           par->rthread = true;
           par->right = ptr->right;
       }
   }
   delete ptr;
}


void deleteNodeWithOneChild(tree* par, tree* ptr,tree* &root) {
   if (par == NULL) {
      
       root = (ptr->lthread == false) ? ptr->left : ptr->right;
   } else {
       if (par->left == ptr) {
          
           par->lthread = false;
           par->left = (ptr->lthread == false) ? ptr->left : ptr->right;
       } else {
          
           par->rthread = false;
           par->right = (ptr->lthread == false) ? ptr->left : ptr->right;
       }
   }
   delete ptr;
}


void deleteNodeWithTwoChildren(tree* root, tree* ptr) {
  
  
   tree* successor = ptr->right;
   while (successor->lthread == false) {
       successor = successor->left;
   }


  
  
   ptr->data = successor->data;


  
  
   if (successor->lthread == true && successor->rthread == true) {
      
      
       deleteLeafNode(ptr, successor,root);
   } else {
      
      
       deleteNodeWithOneChild(ptr, successor,root);
   }
}








tree* deleteNode(tree* root, int key) {
   if (root == NULL) {
       cout << "Key not found in the tree" << endl;
       return root;
   }


   tree* ptr = root;
   tree* par = NULL;
  
  
  
   while (ptr != NULL) {
       if (key == ptr->data) {
           break;
       }
       par = ptr;
       if (key < ptr->data) {
           if (ptr->lthread == false) {
               ptr = ptr->left;
           } else {
               break;
           }
       } else {
           if (ptr->rthread == false) {
               ptr = ptr->right;
           } else {
               break;
           }
       }
   }


 
 
   if (ptr == NULL) {
       cout << "Key not found in the tree" << endl;
       return root;
   }


  
  
   if (ptr->lthread == true && ptr->rthread == true) {
       deleteLeafNode(par, ptr,root);
   }
  
  
   else if (ptr->lthread == true && ptr->rthread == false) {
       deleteNodeWithOneChild(par, ptr,root);
   }
   else if (ptr->lthread == false && ptr->rthread == true) {
       deleteNodeWithOneChild(par, ptr,root);
   }
 
 
   else {
       deleteNodeWithTwoChildren(root, ptr);
   }


   return root;
}


int main() {
   tree* root = NULL;
   root = insert(root, 20);
   root = insert(root, 10);
   root = insert(root, 30);
   root = insert(root, 5);
   root = insert(root, 16);
   root = insert(root, 18);
   root = insert(root, 50);
   root = insert(root, 25);
   root = insert(root, 1);
   root = insert(root, 8);
   cout<<"Inorder traversal: ";
   inorder(root);
   /*cout<<"Preorder traversal: ";
   preorder(root);*/
   cout<<"DELETE leaf NODE: "<<endl;
   cout<<"Enter the leaf node to be deleted: ";
   int n;
   cin>>n;
   tree* root1=deleteNode(root,n);
   cout<<"tree after deletion: ";
   inorder(root1);
   cout<<"DELETE  NODE with one child: "<<endl;
   cout<<"Enter the node to be deleted: ";
   int m;
   cin>>m;
    root1=deleteNode(root,m);
   cout<<"tree after deletion: ";
   inorder(root1);
   cout<<"DELETE NODE with two children: "<<endl;
   cout<<"Enter the node to be deleted: ";
   int p;
   cin>>p;
   root1=deleteNode(root,p);
   cout<<"tree after deletion: ";
   inorder(root1);
  
}






#include <iostream>
#include <string>
using namespace std;

struct Node{
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;
    
    Node(string key,string val): keyword(key),meaning(val),left(nullptr),right(nullptr),height(1) {}
};

int height(Node* n){
    return n? (n->height):0;
}

int getbalance(Node * n){
    return n ? height(n->left) - height(n->right):0;
}

void update(Node *n){
    if(n)
    n->height= 1+(max(height(n->left),height(n->right)));
}

Node* rightrotate(Node* y){
    Node* x=y->left;
    Node* t2=x->right;
    x->right=y;
    y->left=t2;
    update(x);
    update(y);
    return x;
}
Node* leftrotate(Node* x){
    Node* y=x->right;
    Node* t2=y->left;
    y->left=x;
    x->right=t2;
    update(x);
    update(y);
    return y;
}
//inserts or updates
Node* insertnode(Node* n,string key,string val){
    if(!n){
        return new Node(key,val);
    }
    
    if(key<n->keyword){
        n->left=insertnode(n->left,key,val);
    }
    else if(key>n->keyword){
        n->right=insertnode(n->right,key,val);
    }
    else{
        n->meaning=val;
        return n;
    }
    
    update(n);
    int balance=getbalance(n);
    
    if(balance>1 && key<n->left->keyword) return rightrotate(n);
    if(balance<-1 && key>n->right->keyword) return leftrotate(n);
    
    if(balance>1 && key>n->left->keyword){
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }
    if(balance<-1 && key<n->right->keyword){
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
    
}

Node* minvalue(Node* n){
    Node* curr=n;
    while(curr->left){
        curr=curr->left;
    }
    return curr;
}

Node* deletenode(Node* n,string key){
    if(!n) return n;
    
    if(key<n->keyword){
        n->left=deletenode(n->left,key);
    }
    else if(key>n->keyword){
        n->right=deletenode(n->right,key);
    }
    else{
        if(!n->left || !n->right){
            Node* temp=n->left? n->left:n->right;
            delete n;
            return temp;
        }
        else{
            Node* temp=minvalue(n->right);
            n->keyword=temp->keyword;
            n->meaning=temp->meaning;
            n->right=deletenode(n->right,temp->keyword);
            
        }
        
    }
    
    update(n);
    int balance=getbalance(n);
    
    if(balance>1 && getbalance(n->left)>=0) return rightrotate(n);
    if(balance<-1 && getbalance(n->right)<0) return leftrotate(n);
    
    if(balance>1 && getbalance(n->left)<0){
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }
    if(balance<-1 && getbalance(n->right)>=0){
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }
    
    return n;
    
}

bool search(Node* n,string key,int & cmp){
    cmp++;
    if(!n) return false;
    if(key==n->keyword){
        cout<<"Found! "<<n->meaning<<endl;
        return true;
    }
    if(key<n->keyword){
        return search(n->left,key,cmp);
    }
    else{
        return search(n->right,key,cmp);
    }
}

void display(Node* n,bool asc=true){
    if(!n) return;
    if(asc){
        display(n->left,true);
        cout<<"Keyword: "<<n->keyword<<"Meaning: "<<n->meaning<<endl;
        display(n->right,true);
    }
    else{
        display(n->right,false);
        cout<<"Keyword: "<<n->keyword<<"Meaning: "<<n->meaning<<endl;
        display(n->left,false);
        
    }
}

int main() {
    Node* root = nullptr;
    int choice;
    string keyword, meaning;
    
    do {
        cout << "\nDictionary Operations:\n";
        cout << "1. Insert/Update\n2. Delete\n3. Search\n4. Display Ascending\n5. Display Descending\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                root = insertnode(root, keyword, meaning);
                cout << "Inserted/Updated.\n";
                break;
            case 2:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                root = deletenode(root, keyword);
                cout << "Deleted.\n";
                break;
            case 3: {
                cout << "Enter keyword to search: ";
                cin >> keyword;
                int comps = 0;
                if (!search(root, keyword, comps))
                    cout << "Not found.\n";
                cout << "Comparisons made: " << comps << endl;
                break;
            }
            case 4:
                cout << "\nDictionary in Ascending Order:\n";
                display(root, true);
                break;
            case 5:
                cout << "\nDictionary in Descending Order:\n";
                display(root, false);
                break;
        }
    } while (choice != 6);

    return 0;
}



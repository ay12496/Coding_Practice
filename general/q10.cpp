#include <bits/stdc++.h>  
  
using namespace std;  
  
/* A binary tree Node has data,  
pointer to left child and  
a pointer to right child */
class Node  
{public:
    int key;  
    Node* left;
    Node* right;
    Node(int key){
        this->key=key;
        this->left=nullptr;
        this->right=nullptr;
    }
}; 


string path="";
int findMirror(Node* root, int target, string str){
    if(root){
        if(root->key==target){
            path=str;
            return 1;
        }
        int kleft=findMirror(root->left, target,str+"l");
        int kright=findMirror(root->left, target,str+"r");
        if(kright==-1){
            if(kleft==-1){
                return -1;
            }
            else{
                return kleft;
            }
        }else{
            return kright;
        }
    }
    return -1;
}

// Driver Code 
int main()  
{  
    struct Node* root = new Node(1);  
    root-> left = new Node(2);  
    root->left->left = new Node(4);  
    root->left->left->right    = new Node(7);  
    root->right    = new Node(3);  
    root->right->left = new Node(5);  
    root->right->right = new Node(6);  
    root->right->left->left    = new Node(8);  
    root->right->left->right = new Node(9);  
  
    // target Node whose mirror have to be searched  
    int target = root->left->left->key;  
  
    int mirror = findMirror(root, target,"");
    Node* ptr=root;
    int ans=-1;
    if(mirror!=-1){
        for(char a:path){
            if(a=='r'){
                if(root)
                    root=root->right;
            }
            else{
                if(root)
                    root=root->left;
            }

        }
        if(root){
            ans=root->key;
        }
        if(ans==-1){
            cout << "Mirror of Node " << target  
             << " is NULL! " << endl;
        }else{
            cout << "Mirror of Node " << target  
             << " is Node " << ans << endl;  
        }  
        
    }
    else
        cout << "Mirror of Node " << target  
             << " is NULL! " << endl;  
}  
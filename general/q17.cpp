#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* right;
    Node* left;
    int pos;
    Node(int value){
        this->value = value;
        this->right = NULL;
        this->left = NULL;
        this->pos=-1;
    }
};

map<int, int> view;

void preorder_traversal(Node* root, int curr_pos){
    if(root){
        if(view.count(curr_pos)==0)
            view[curr_pos]=root->value;
        preorder_traversal(root->left,curr_pos -1);
        preorder_traversal(root->right,curr_pos +1);
    }
}


void topview(Node* root){
    Node* curr = root;
    //preorder_traversal(curr,0);
    queue<Node*> q = queue<Node*>();
    int curr_pos=0;
    curr->pos=curr_pos;
    q.push(curr);
    while(q.size()){
        Node* curr= q.front();
        q.pop();
        if(view.count(curr->pos)==0)
            view[curr->pos]=curr->value;
        if(curr->left){
            curr->left->pos=curr->pos-1;
            q.push(curr->left);
        }
        if(curr->right){
            curr->right->pos=curr->pos+1;
            q.push(curr->right);
        }
    }
    for(auto it = view.begin(); it!=view.end();it++){
        cout<<it->second<<"\t";
    }
    cout<<endl;
    for(auto it = view.begin(); it!=view.end();it++){
        cout<<it->first<<"\t";
    }
    cout<<endl;
}

void bottomview(Node* root){
    Node* curr = root;
    //preorder_traversal(curr,0);
    queue<Node*> q = queue<Node*>();
    int curr_pos=0;
    curr->pos=curr_pos;
    q.push(curr);
    while(q.size()){
        Node* curr= q.front();
        q.pop();
        view[curr->pos]=curr->value;
        if(curr->left){
            curr->left->pos=curr->pos-1;
            q.push(curr->left);
        }
        if(curr->right){
            curr->right->pos=curr->pos+1;
            q.push(curr->right);
        }
    }
    for(auto it = view.begin(); it!=view.end();it++){
        cout<<it->second<<"\t";
    }
    cout<<endl;
    for(auto it = view.begin(); it!=view.end();it++){
        cout<<it->first<<"\t";
    }
    cout<<endl;
}

int main(){
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->right = new Node(4); 
    root->left->right->right = new Node(5); 
    root->left->right->right->right = new Node(6); 
    cout<<"Following are nodes in top view of Binary Tree\n";  
    topview(root); 
    cout<<"Following are nodes in bottom view of Binary Tree\n";  
    bottomview(root); 
    return 0;
}
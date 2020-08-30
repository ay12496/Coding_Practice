//Diameter of a Binary Tree

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int value;
    node* lchild;
    node* rchild;
    node(int value){
        this->value =value;
        this->rchild = nullptr;
        this->lchild = nullptr;
    }
};
struct tree{
    node* root;
};

int max_sum = -1;

int height_tree(node* parent){
    if(parent){
        int lheight = height_tree(parent->lchild);
        int rheight = height_tree(parent->rchild);
        max_sum = max(lheight+rheight +1,max_sum);
        return max(lheight,rheight)+1;
    }
    return 0;
}

int main(){
    tree t1;
    t1.root= new node(4);
    t1.root->rchild= new node(5);
    t1.root->rchild->rchild= new node(6);
    t1.root->rchild->rchild->rchild= new node(6);
    t1.root->rchild->rchild->rchild->rchild= new node(6);
    t1.root->rchild->rchild->rchild->rchild->rchild= new node(6);
    t1.root->lchild = new node(5);
    t1.root->lchild->rchild = new node(6);
    t1.root->lchild->lchild = new node(5);
    t1.root->lchild->lchild->rchild = new node(1);
    t1.root->lchild->lchild->lchild = new node(-8);
    t1.root->lchild->lchild->lchild->rchild = new node(6);
    t1.root->lchild->lchild->lchild->lchild = new node(2);
    t1.root->lchild->rchild->rchild = new node(9);
    t1.root->lchild->rchild->lchild = new node(3);
    t1.root->lchild->rchild->rchild->rchild = new node(0);
    t1.root->lchild->rchild->rchild->rchild->lchild = new node(4);
    t1.root->lchild->rchild->rchild->rchild->rchild = new node(-1);
    t1.root->lchild->rchild->rchild->rchild->rchild->lchild = new node(10);
    height_tree(t1.root);
    //ans = max_sum > ans ? max_sum : ans ;
    cout<<max_sum<<endl;
    return 0;
}
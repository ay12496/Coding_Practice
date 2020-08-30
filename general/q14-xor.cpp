#include<bits/stdc++.h>
#include <inttypes.h>  

using namespace std;

class LL_XOR{
public:
    int value;
    LL_XOR* ptrdiff;
    LL_XOR(int value){
        this->value = value;
        this->ptrdiff = NULL;
    }
};


int main(){
    LL_XOR *root, *curr;
    LL_XOR *prev=NULL, *next=NULL;
    root= new LL_XOR(0);
    root->ptrdiff = NULL;
    prev = root; 
    for (int i=0;i<10;i++){
        curr = new LL_XOR(i+1);
        prev->ptrdiff=(LL_XOR*)(((uintptr_t)curr)^((uintptr_t)prev->ptrdiff));
        curr->ptrdiff=prev;
        prev=curr;
    }
    prev=NULL;
    curr=NULL;
    next=NULL;
    curr=root;
    for (int i=0;i<5;i++){
        cout<<curr->value<<"\t";
        next=(LL_XOR*)(((uintptr_t)prev)^((uintptr_t)curr->ptrdiff));
        prev=curr;
        curr=next;        
    }
    curr=prev;
    for (int i=0;i<5;i++){
        cout<<curr->value<<"\t";
        prev=(LL_XOR*)(((uintptr_t)next)^((uintptr_t)curr->ptrdiff));
        next=curr;
        curr=prev;        
    }
    cout<<endl;
    return 0;
}
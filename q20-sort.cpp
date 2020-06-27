#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    Node(int value=0){
        this->value =value;
        this->next = NULL;
    }
};

class ll{
public:
    Node* head;
    Node* tail;
    int size;
    
    ll(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    void insert(Node* ele){
        size++;
        if(!head){
            head=ele;
            tail=ele;
        }else{
            tail->next = ele;
            tail = ele;
        }
    }
};


void sort(ll &list, int chunk){
    for(int i=0; i < list.size; i+=chunk){
        auto curr = list.head;
        Node* prev;
        for(int j=0; j < list.size-chunk; j+=chunk){
            int sum1=0,sum2=0;
            Node *start1, *end1, *start2, *end2;
            start1=curr;
            for(int k=0;k<chunk;k++){
                sum1 += curr->value;
                end1=curr;
                curr=curr->next;
            }
            start2=curr;
            for(int k=0;k<chunk;k++){
                sum2 += curr->value;
                end2=curr;
                curr =curr->next;
            }
            if(sum1>sum2){
                Node* temp =end2->next;
                end2->next=start1;
                end1->next=temp;
                if(start1==list.head)
                    list.head =start2;
                else{
                    prev->next=start2;
                }
                curr=start1;
                prev=end2;
            }else{   
                curr=start2;
                prev=end1;
            }
        }
    }
}


int main(){
    ll list;
    list.insert(new Node(12));
    list.insert(new Node(1));
    list.insert(new Node(10));
    list.insert(new Node(3));
    list.insert(new Node(5));
    list.insert(new Node(7));
    list.insert(new Node(21));
    list.insert(new Node(15));
    list.insert(new Node(19));
    list.insert(new Node(7));
    list.insert(new Node(18));
    list.insert(new Node(3));
    sort(list, 6);
    auto curr = list.head;
    for(int i=0;i<list.size;i++){
        cout<<curr->value<<"\t";
        curr=curr->next;
    }
    cout<<endl;
    return 0;
}
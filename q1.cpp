#include <iostream>

using namespace std;

struct node{
    int num;
    node* next;
};


class LL{
public:
    node* head;
    node* tail;

    LL(){
        head=nullptr;
        tail=nullptr;
    }

    void insertLL(int num){
        node* n = new node();
        n->num=num;
        n->next=nullptr;
        if(head==nullptr){
            head= n;
            tail=n;
        }
        tail->next=n;
        tail=n;
    }
};


void swap(int a[],int m,int n){
    int temp=a[m];
    a[m]=a[n];
    a[n]=temp;
}

void heapify(int a[],int i, int size){
    int lchild=2*i+1;
    int rchild=2*i+2;

    int largest=i;
    if(lchild<size)
        if(a[largest]<a[lchild])
            largest=lchild;
    if(rchild<size)
        if(a[largest]<a[rchild])
            largest=rchild;
    if(largest!=i){
        swap(a,i,largest);
        heapify(a,largest,size);
    }
}


void heap_sort(int a[], int size){
    for(int i=size/2 - 1;i>=0;i--){
        heapify(a, i, size);
    }
    swap(a,0,size-1);
    for(int last_ele=size-2;last_ele>=0;last_ele--){
        heapify(a,0,last_ele+1);
        swap(a, 0,last_ele);
    }
}

node* merge(LL l1, LL l2, int size1, int siz2){
    node* curr1=l1.head;
    node* curr2=l2.head;
    node* last=nullptr;
    node* start=nullptr;
    if(curr1==nullptr)
        if(curr2==nullptr)
            return nullptr;
        else
            return curr2;
    else
        if(curr2==nullptr)
            return curr1;

    
    if(curr1->num <= curr2->num){
        last=curr1;
        start=last;
        curr1= curr1->next;
    }
    else{
        last=curr2;
        start=last;
        curr2=curr2->next;
    }
    while(curr1 !=nullptr && curr2 != nullptr){
        if(curr1->num<=curr2->num){
            last->next=curr1;
            last=curr1;
            curr1=curr1->next;
        }else{
            last->next=curr2;
            last=curr2;
            curr2=curr2->next;
        }   
    }
    if(curr1==nullptr){
        last->next=curr2;
    }
    if(curr2==nullptr){
        last->next=curr1;
    }
    return start;
}


int main(){
    int arr1[]={134,5,43,1,4,1332,3,45,2};
    int arr2[]={67,89,12,35,33};
    heap_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    heap_sort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    LL l1,l2;
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
        l1.insertLL(arr1[i]);
    for(int i=0;i<sizeof(arr2)/sizeof(arr2[0]);i++)
        l2.insertLL(arr2[i]);
    node* ptr = merge(l1,l2,sizeof(arr1)/sizeof(arr1[0]),sizeof(arr2)/sizeof(arr2[0]));
    while(ptr){
        cout<<ptr->num<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
    return 0;
}
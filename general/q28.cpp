//Find the smallest positive number missing from an unsorted array
#include<bits/stdc++.h>
using namespace std;

int segregate(int arr[], int size){
    int i=0, pos=-1; //i=counter, pos=next positve ele in the array.
    while(i<size){
        if(arr[i]>0)
            arr[++pos]=arr[i];
        i++;
    }
    return pos;
}

int main(){
    int arr[10]={10,-2,5,3,7,9,1,2,3,-1};
    int last_index = segregate(arr, 10);
    if(last_index>=0){
        int i=0;
        for (;i<=last_index;i++){
            if(abs(arr[i])<=last_index)
                arr[abs(arr[i])]=-abs(arr[abs(arr[i])]);
        }
        i=1;
        while(i<=last_index){
            if(arr[i]>0){
                cout<<"smallest post ele: "<<i<<endl;
                break;
            }
            i++;
        }
    }else{
        cout<<"No positve element present"<<endl;
    }
    return 0;
}
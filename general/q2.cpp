#include <iostream>
using namespace std;

int arr[] = { 1,1,0,0,0,0,0,0,0,0,0,1,0, 1, 0, 1, 1, 1 }; 

void swap(int i, int j){
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int main(){
    int n = sizeof(arr) / sizeof(arr[0]);

    int ele_counter=0, swap_pos=0;
    for(;ele_counter<n;ele_counter++){
        if(arr[ele_counter]==0){
            swap(swap_pos,ele_counter);
            swap_pos++;            
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
//Given a sorted array and an element x, find k closest elements to the x in an array

#include<bits/stdc++.h>

using namespace std;

int binary_search(int arr[], int x, int size){
    int l=0, r=size-1, mid;
    while(1){
        if(l<=r){
            mid= (l+r)/2;
            if(arr[mid]==x){
                return mid;
            }
            if(arr[mid]>x){
                r=mid-1;
            }else{
                l=mid+1;
            }
            if(r==l){
                return r;
            }
        }
    }
    return -1;
}

int main(){
    int size=6;
    int arr[]={12,15,18,20,22,23}, k=4, x=20;
    sort(arr, arr+size); //sorting
    int index = binary_search(arr, x, size);
    cout<<"index:"<<index<<endl;
    int wl=index-1,wr=index;
    if(arr[wr]==x)
        wr++;
    int diff_r=0, diff_l=0;
    while(k && (diff_r!=INT_MAX || diff_r!=INT_MAX )){
        if(wr<size)
            diff_r = arr[wr]-x;
        else
            diff_r = INT_MAX;
        if(wl>=0)
            diff_l = x - arr[wl];
        else
            diff_l = INT_MAX;
        
        if(diff_l< diff_r){
            cout<<arr[wl]<<endl;
            wl--;
            k--;
        }
        else{
            cout<<arr[wr]<<endl;
            wr++;
            k--;
        }
    }
    return 0;
}
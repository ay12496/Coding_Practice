//longest sub sequence

#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={3,4,-1,0, 2,3,6};
    int ele_less_than[]={1,1,1,1,1,1,1};
    int size= sizeof(arr)/sizeof(arr[0]);
    int max_count=1;
    for(int i=1;i<size;i++){
        for(int j=0;j<i;j++){
            cout<<arr[j]<<"\t"<<arr[i];
            if(arr[j]<arr[i]){
                if(ele_less_than[i]<ele_less_than[j]+1){
                    ele_less_than[i]=ele_less_than[j]+1;
                    cout<<"\t"<<ele_less_than[i];
                }
            }
            cout<<endl;
        }
    }
    for(int i=1;i<size;i++){
        if(max_count<ele_less_than[i])
            max_count=ele_less_than[i];
    }
    cout<<max_count<<endl;
    return 0;
}
//Partition a set into two subsets such that the difference of subset sums is minimum
#include<bits/stdc++.h>
using namespace std;

// int min_res=INT_MAX;

#define MAX_SIZE 10
#define MAX_SUM 100

int total_sum=0;
bool mat[MAX_SIZE][MAX_SUM];

int fn(int arr[], int index, int size, int sum){
    if(index<size){
        return total_sum -2*sum>0 ? min(fn(arr,index+1,size, sum+ arr[index]),fn(arr,index+1,size, sum)) : INT_MAX; //optimisation, not sure it makes sense of not)
    }else{
        return total_sum -2*sum>0 ? total_sum - 2*sum : INT_MAX;
    }
}


//dp
int dp_fn(int arr[], int index, int size, int sum){
    for(int i=1;i<=total_sum;i++)
        mat[0][i]=false;  //no element selected will result in no sum greater than zero hence d[0][1] .. d[0][n] all are false.
    for(int i=0;i<=size;i++)
        mat[i][0]=true;   //similarly sum can always be zero with no element selected d[0][0].. d[n][0] are true.

    for(int i=1;i<=size;i++){
        for(int j=1; j<total_sum;j++){
            mat[i][j] = mat[i-1][j]; //element at ith location no selected(by default)
            //selecting first ele in array.
            if(arr[i-1]<=j) {
                mat[i][j] |= mat[i-1][j-arr[i-1]]; //checking is previous row if there is sum true, current sum - arr[i-1] curr ele
            }
        }
    }

    for(int i=total_sum/2;i>0;i--){
        if(mat[size][i])
            return total_sum -2*i;
    }

    return -1;
}

int main(){
    // int  arr[]={10,34,12,10,98,90,18};
    int  arr[]={10,34,12,10};
    int size=sizeof(arr)/sizeof(int);
    
    for(int i=0;i<size;i++)
        total_sum+=arr[i];
    cout<<fn(arr, 0, size   , 0)<<endl;
    cout<<dp_fn(arr, 0, size, 0)<<endl;
    return 0;
}
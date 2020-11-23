//subset sum problem
//https://www.interviewbit.com/problems/subset-sum-problem/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={8,7,3,2,10};
    int num_ele=sizeof(arr)/sizeof(arr[0]);
    int sum=13;
    int mat[2][sum+1];
    mat[0][0]=1;
    mat[1][0]=1;
    for(int i=1;i<sum+1;i++){
        mat[0][i]=0;
        mat[1][i]=0;
    }
    for(int i=0;i<num_ele;i++){
        for(int j=arr[i];j<=sum;j++){
            if(mat[0][j-arr[i]]==1){
                mat[1][j]=1;
            }else{
                mat[1][j]=mat[0][j];
            }
        }
        for(int j=0;j<=sum;j++)
            mat[0][j]=mat[1][j];
    }
    cout<<mat[1][sum]<<endl;
    return 0;
}
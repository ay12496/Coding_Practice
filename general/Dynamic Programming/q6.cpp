//subset sum
//https://www.interviewbit.com/problems/subset-sum-problem/

#include<bits/stdc++.h>

using namespace std;

int subset_sum(vector<int> &A, int B) {
    int mat[2][B+1];
    mat[0][0]=1;
    mat[1][0]=1;
    for(int i=1;i<B+1;i++){
        mat[0][i]=0;
        mat[1][i]=0;
    }
    for(int i=0;i<A.size();i++){
        for(int j=A[i];j<=B;j++){
            if(mat[0][j-A[i]]==1){
                mat[1][j]=1;
            }else{
                mat[1][j]=mat[0][j];
            }
        }
        for(int j=0;j<=B;j++)
            mat[0][j]=mat[1][j];
    }
    return mat[0][B];
}


int main(){
    vector<int> A = vector<int>({3, 34, 4, 12, 5, 2});
    int sum=9;
    cout<<subset_sum(A,sum)<<endl;
    return 0;
}
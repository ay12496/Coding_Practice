//Min Steps in Infinite Grid
#include<bits/stdc++.h>

using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
    int pos_row=A[0], pos_col=B[0];
    int steps=0,row_step, col_step;
    for(int i=1;i<A.size();i++){
        row_step=abs(A[i]-pos_row);
        col_step=abs(B[i]-pos_col);
        if(row_step<col_step){
            steps += col_step;
        }else{
            steps += row_step;
        }
        pos_row = A[i];
        pos_col = B[i];
    }
    return steps;
}

int main(){
    vector<int> A = vector<int>(100,0);
    vector<int> B = vector<int>(100,0);
    int num_points=0;
    cin>>num_points;
    A.resize(num_points);
    B.resize(num_points);
    for(int i=0;i<num_points;i++){
        cin>>A[i]>>B[i];
    }
    cout<<coverPoints(A,B)<<endl;
    return 0;
}
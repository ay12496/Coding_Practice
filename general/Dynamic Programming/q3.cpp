// matrix multiplication chain
#include<bits/stdc++.h>

using namespace std;

struct mat{
    int row;
    int col;
};

int min_matrix_mul_cost(vector<mat> matrix_list){
    vector<vector<int>> mat_cost = vector<vector<int>>(matrix_list.size(),vector<int>(matrix_list.size(),0));
    for(int len=2;len<=matrix_list.size();len++){
        for(int j=0;j+len<=matrix_list.size();j++){
            mat_cost[j][j+len-1]=INT_MAX;
            for(int i=0;i<len-1;i++){
                mat_cost[j][j+len-1] = min(mat_cost[j][j+len-1],
                                mat_cost[j][j+i]+mat_cost[j+i+1][j+len-1]+ matrix_list[j].row*matrix_list[j+i+1].row*matrix_list[j+len-1].col);
            }
        }
    }
    return mat_cost[0][matrix_list.size()-1];
}


int main(){
    vector<mat> matrix_list = vector<mat>({{2,3},{3,6},{6,4},{4,5}});
    cout<<min_matrix_mul_cost(matrix_list)<<endl;
    return 0;
}
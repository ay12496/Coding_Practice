//matrix-multiplication

#include<bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000

int min_matrix_cost[MAX_SIZE][MAX_SIZE];


void matrix_mul_min_cost(int matrix_dim[][2], int matrix_array_size){
    memset(min_matrix_cost, 0, matrix_array_size*2);
    for(int i=1;i<matrix_array_size; i++){
        for(int j=0; j<matrix_array_size-1;j++){ //i is equal to num of array included to multiply
            if(i==1){
                min_matrix_cost[j][j+1]=matrix_dim[j][0]*matrix_dim[j][1]*matrix_dim[j+1][1]; //mat[a]*mat[a+1] = mat[a][0]*mat[a][1]*mat[a+1][2]; mat[a][1] == mat[a+1][0];
            }else{
                min_matrix_cost[j][j+i] = min(min_matrix_cost[j][j+i-1] + matrix_dim[j][0]*matrix_dim[j+i][0]*matrix_dim[j+i][1],
                                          min_matrix_cost[j+1][j+i] + matrix_dim[j][0]*matrix_dim[j][1]*matrix_dim[j+i][1]);
            }
        }
    }

    
}


int main(){
    int matrix_dim[][2] = {{2,5},{5,6},{6,2},{2,7},{7,9},{9,3},{3,6},{6,4},{4,8},{4,1}};
    int matrix_array_size = sizeof(matrix_dim)/sizeof(matrix_dim[0]);
    matrix_mul_min_cost(matrix_dim, matrix_array_size);
    cout<<"ans:"<<min_matrix_cost[0][matrix_array_size-1]<<endl;
    return 0;
}
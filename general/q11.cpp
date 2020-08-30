#include <bits/stdc++.h> 
using namespace std; 
  
#define ROW 5 
#define COL 5 

int visited[ROW][COL] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

struct point{
    int r;
    int c;
};
vector<point> land_list;

void dfs(int r,int c, int M[][COL]){
    if(r<ROW && r>=0 && c>=0 && c<COL){
        if(M[r][c]==1 && visited[r][c]==0){
            visited[r][c]=1;
            dfs(r+1,c,M);
            dfs(r-1,c,M);
            dfs(r,c+1,M);
            dfs(r,c-1,M);
            dfs(r+1,c+1,M);
            dfs(r-1,c-1,M);
            dfs(r-1,c+1,M);
            dfs(r+1,c-1,M);
        }
    }
}

int countIslands(int M[ROW][COL]){
    point l;
    int island_count=0;
    for(auto land: land_list){
        l=land;
        if(visited[l.r][l.c]==0){
            dfs(l.r,l.c, M);
            island_count++;
        }
        
    }
    return island_count;
}


// Driver code 
int main() 
{ 
    int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 1, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
    
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(M[i][j]==1)
                land_list.push_back({i,j});          
        }
    }
    cout << "Number of islands is: " << countIslands(M)<<endl; 
  
    return 0; 
} 
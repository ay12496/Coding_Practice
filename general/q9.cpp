#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 5

struct point{
    int r;
    int c;
};

bool ispossible(int r,int c){
    return r<R && r>=0 && c<C && c>=0;
}

int rotOranges(int v[R][C]){
    queue<point> rotten_list;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(v[i][j]==2)
                rotten_list.push({i,j});
        }       
    }
    point temp;
    bool changed=false;
    queue<point> temp_list;
    int day=0;
    while(true){
        if(rotten_list.empty()){
            break;
        }
        while(!rotten_list.empty()){
            temp_list.push(rotten_list.front());
            rotten_list.pop();
        }
        while(!temp_list.empty()){
            temp= temp_list.front();
            if(ispossible(temp.r - 1,temp.c)){
                if(v[temp.r -1][temp.c]==1){
                    v[temp.r -1][temp.c]=2;
                    rotten_list.push({temp.r-1,temp.c});
                }
            }
            if(ispossible(temp.r + 1,temp.c)){
                if(v[temp.r +1][temp.c]==1){
                    v[temp.r +1][temp.c]=2;
                    rotten_list.push({temp.r+1,temp.c});
                }
            }
            if(ispossible(temp.r,temp.c -1)){       
                if(v[temp.r][temp.c - 1]==1){
                    v[temp.r][temp.c - 1]=2;
                    rotten_list.push({temp.r,temp.c-1});
                }
            }
            if(ispossible(temp.r,temp.c+1)){
                if(v[temp.r][temp.c + 1]==1){
                    v[temp.r][temp.c + 1]=2;
                    rotten_list.push({temp.r,temp.c + 1});
                }
            }
            temp_list.pop();
        }
        day++;
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(v[i][j]==1)
                return -1;
        }       
    }
    return day-1; //minus 1 as last nothing happened
}


int main(){
    int v[R][C] = { { 2, 0, 0, 2, 1 }, 
                    { 0, 1, 0, 2, 1 }, 
                    { 1, 1, 0, 2, 1 } }; 
    cout << "Max time incurred: " << rotOranges(v)<<endl; 
    return 0; 
}
#include<bits/stdc++.h>
using namespace std;

void numways_jump_path(int pos){
    vector<int> numways_path = vector<int>(pos+1,0);
    numways_path[0]=0;
    for(int  i=1;i<=pos;i++){
        for(int jump_length=1;jump_length<i;jump_length++){
            numways_path[i]+=numways_path[i-jump_length];
        }
        if(i>0)
         numways_path[i]++; //directjump
        cout<<"pos "<<i<<" : "<<numways_path[i]<<endl;
    }
    
}

int main(){
    numways_jump_path(15);
    return 0;
}
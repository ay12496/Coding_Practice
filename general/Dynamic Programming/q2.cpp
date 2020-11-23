// Longest common subsequence

#include<bits/stdc++.h>

using namespace std;

int main(){
    string str1="acbcf";
    string str2="abcdef";
    
    vector<vector<int>> mat = vector<vector<int>>(str1.length()+1,vector<int>(str2.length()+1,0));
    // mat[str1_length+1][str2_length+1]
    
    for(int i=1;i<str1.length()+1;i++){
        for(int j=1;j<str2.length()+1;j++){
            if(str1[i-1]==str2[j-1]){
                mat[i][j]=mat[i-1][j-1]+1;
            }else{
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    cout<<"lcs of '"<<str1<<"' and '"<<str2<<"' : "<<mat[str1.length()][str2.length()]<<endl;
    return 0;
}
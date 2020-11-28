//Edit Distance 
//https://leetcode.com/problems/edit-distance/


#include<bits/stdc++.h>

using namespace std;

int minDistance(string s1, string s2) {
    vector<vector<int>> dp(s2.length()+1, vector<int>(s1.length()+1));
    dp[0][0]=0;
    for(int i=1;i<=s2.length();i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=s1.length();i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=s2.length();i++){
        for(int j=1;j<=s1.length();j++){
            if(s2[i-1]==s1[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=min(min(dp[i-1][j-1], dp[i][j-1]),dp[i-1][j])+1;
            }
        }
    }
    return dp[s2.length()][s1.length()];
}

int main(){
    cout<<minDistance("horse","ros")<<endl;
    return 0;
}
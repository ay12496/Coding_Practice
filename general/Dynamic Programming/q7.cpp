//number of way of getting coin change
//https://www.interviewbit.com/problems/subset-sum-problem/

#include<bits/stdc++.h>

using namespace std;

int num_change(int sum, vector<int>& coin) {
    int num_coin=coin.size();
    vector<vector<int>> dp(num_coin+1,vector<int>(sum+1,0));
    dp[0][0]=1;
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;
    for(int j=1;j<=num_coin;j++)
        dp[j][0]=1;
    for(int i=1;i<=num_coin;i++){
        for(int j=1;j<=sum;j++){
            if(j-coin[i-1]>=0)
                dp[i][j]=dp[i-1][j] + dp[i][j-coin[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }   
    }
    
    return dp[num_coin][sum];
}

int main(){
    vector<int> coins=vector<int>({1,2,5});
    int sum=5;
    cout<<num_change(sum,coins)<<endl;
    return 0;
}
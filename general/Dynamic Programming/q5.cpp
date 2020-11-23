//coin change
//https://leetcode.com/problems/coin-change/
#include<bits/stdc++.h>

using namespace std;

int coinchange_BOTUP(vector<int> &coin, int sum){
    int num_coin = coin.size();
    vector<int> min_coin = vector<int>(sum+1, INT_MAX);
    min_coin[0]=0;
    for(int i=0;i<num_coin;i++){
        for(int curr_sum=coin[i];curr_sum<=sum;curr_sum++){
            if(min_coin[curr_sum-coin[i]]!=INT_MAX)
                min_coin[curr_sum] = min(min_coin[curr_sum], min_coin[curr_sum-coin[i]]+1);
        }
    }
    if(min_coin[sum]==INT_MAX)
        return -1;
    return min_coin[sum];
}


int coinchange_TOPDW_rec(vector<int>& coin,int sum,vector<int>& dp);

int coinchange_TOPDW(vector<int>& coin, int sum){
    if(sum<1)
        return 0;
    vector<int> dp = vector<int>(sum+1);
    dp[0]=0;
    return coinchange_TOPDW_rec(coin, sum, dp);
}

int coinchange_TOPDW_rec(vector<int>& coin,int sum,vector<int>& dp){
    if(sum<0){
        return INT_MAX;
    }
    if(sum==0){
        return 0;
    }
    if(dp[sum]!=0){
        return dp[sum];
    }
    int min_coin=INT_MAX;
    for(int i=0;i<coin.size();i++){
        int temp=coinchange_TOPDW_rec(coin, sum-coin[i], dp);
        if(temp!=INT_MAX){
            min_coin= min(min_coin, temp+1);
        }
    }
    dp[sum]=min_coin;
    return dp[sum];
}

int coinchange_TOPDW_no_save(vector<int>& coin,int sum){
    if(sum<0){
        return INT_MAX;
    }
    if(sum==0){
        return 0;
    }
    // if(dp[sum]!=0){
    //     return dp[sum];
    // }
    int min_coin=INT_MAX;
    // cout<<sum<<endl;
    for(int i=0;i<coin.size();i++){
        int temp=coinchange_TOPDW_no_save(coin, sum-coin[i]);
        if(temp!=INT_MAX){
            min_coin= min(min_coin, temp+1);
        }
    }
    return min_coin;
}


int main(){
    vector<int> coin = vector<int>({83,419,408,186});
    int sum=6249;
    cout<<coinchange_BOTUP(coin,sum)<<endl;
    cout<<coinchange_TOPDW(coin,sum)<<endl;
    cout<<coinchange_TOPDW_no_save(coin,sum)<<endl;
    return 0;
}
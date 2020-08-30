#include<bits/stdc++.h>
using namespace std;

void coin_change(int amt, vector<int> coin_denomination){
    vector<vector<int>> dp=vector<vector<int>>();
    dp.resize(coin_denomination.size()+1);

    //matrix and initializing it
    dp[0] = vector<int>(amt + 1, INT_MAX-1);
    dp[0][0] = 0;
    for(int i=1;i<coin_denomination.size()+1;i++){
        dp[i] = vector<int>(amt + 1, 0);
    }

    for(int i=1;i<=coin_denomination.size();i++){
        for(int j=1;j<=amt;j++){
            if(coin_denomination[i-1]<=j){
                int num_coin = j/coin_denomination[i-1];
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-coin_denomination[i-1]*num_coin] +num_coin);  //coin_denomination index range from 0..n;
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-coin_denomination[i-1]] +1);
            }else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    for(int i=1;i<=coin_denomination.size();i++){
        for(int j=1;j<=amt;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> coin_denomination = vector<int>({1,3,5,10});
    coin_change(20, coin_denomination);
    return 0;
}
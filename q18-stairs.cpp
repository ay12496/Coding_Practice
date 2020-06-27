#include<bits/stdc++.h>
using namespace std;
unsigned long long table[1000];

unsigned long long nthStair(int n){
    unsigned long long ans=0;
    if(n<0)
        ans = 0;
    else if(n==0)
        ans = 1;
    else
        ans = (table[n-1] ? table[n-1] : nthStair(n-1)) + (table[n-2] ? table[n-2] : nthStair(n-2));
    table[n]=ans;
    return ans;
}

unsigned long long nthStair_ksteps(int n, int k){
    unsigned long long ans=0;
    if(n<0)
        ans = 0;
    else if(n==0)
        ans = 1;
    else{
        for(int step_size=1;step_size<=k && n-step_size>=0;step_size++)
            ans += table[n-step_size] ? table[n-step_size] : nthStair_ksteps(n-step_size,k);;
    }
    table[n]=ans;
    return ans;
}

int main(){
    // \for k-steps num of ways to reach nthstair.
    for(int i=1;i<=92;i++){
        memset(table,0, sizeof(table));
        cout<<i<<"\t"<<nthStair_ksteps(i,i)<<endl;
    }
    return 0;
}
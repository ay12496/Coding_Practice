#include<bits/stdc++.h>

using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum=0;
    for(auto ele: A)
        sum+=ele;
    int sum_till_now=0;
    int ans=INT_MAX;
    for(int i=1;i<A.size()-1;i++){
        sum_till_now+=A[i];
        if(abs(sum_till_now-sum)<ans){
            ans=abs(sum_till_now-sum);
        }
    }
    return ans;
}
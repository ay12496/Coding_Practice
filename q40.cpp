//Incomplete minabs()

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    long long sum=0;
    for(auto it=A.begin();it!=A.end();it++){
        *it = *it<0 ? (*it)*-1: *it;
        sum+=*it;
    }
    
    sort(A.begin(),A.end());
    
    for(auto it=A.end();it!=A.begin();it--){
        auto index= it-1;
        if((*index)*2<=sum){
            sum-=(*index)*2;
        }
    }
    return sum;
}


int main(){
    vector<int> arr=vector<int>({20000,24000,500,5000});
    cout<<solution(arr)<<endl;
    return 0;

}
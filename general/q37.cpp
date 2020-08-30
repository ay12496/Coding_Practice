// rotate an array

#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int size=A.size();
    vector<int> v = vector<int>();
    v.resize(size);
    int count=0;
    if(size==0){
        return v;
    }

    int k=K%size;
    for(int i=size-k;i<size;i++){
        v[count++]= A[i];
    }
    for(int i=0;i<size-k;i++){
        v[count++]= A[i];
    }
    return v;
}


int main(){
    vector<int> ans= vector<int>({1,2});
    vector<int> b = solution(ans,5);
    vector<int> c = vector<int>();
    for(int ele: b)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}



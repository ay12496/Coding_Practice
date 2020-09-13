//Maximum Absolute Difference

#include<bits/stdc++.h>

using namespace std;

int maxArr(vector<int> &A) {
    // int max_value=INT_MIN;
    // for(int i=0;i<A.size();i++){
    //     for(int j=i+1;j<A.size();j++){
    //         max_value = (abs(A[i]-A[j]) + abs(i-j))>max_value ? abs(A[i]-A[j]) + abs(i-j) : max_value;
    //     }
    // }
    
    //type[0] = A[x]+x;
    //type[1] = A[x]-x;
    //type[2] = -A[x]+x;
    //type[3] = -A[x]-x;
    
    int max_type[2]={INT_MIN,INT_MIN};
    int min_type[2]={INT_MAX,INT_MAX};
    int max_ans=0;
    for(int i=0;i<A.size();i++){
        max_type[0]=max(max_type[0],A[i]+i);
        max_type[1]=max(max_type[1],A[i]-i);
        
        min_type[0]=min(min_type[0],A[i]+i);
        min_type[1]=min(min_type[1],A[i]-i);
    }
    max_ans=max_type[0]-min_type[0];
    max_ans=max(max_ans,max_type[1]-min_type[1]);
    return max_ans;
}

int main(){
    vector<int> A = vector<int>({1,3,-1,4,-5,6,7,-8,9,-10,2,7,-4});
    cout<<maxArr(A)<<endl;
    return 0;
}

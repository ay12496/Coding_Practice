//Max Sum Contiguous Subarray
#include<bits/stdc++.h>

using namespace std;

int maxSubArray(const vector<int> &A) {
    int max_sum=INT_MIN;
    int curr_sum=0;
    for(int i=0;i<A.size();i++){
        curr_sum+=A[i];
        if(curr_sum>max_sum)
            max_sum=curr_sum;
        if(curr_sum<0)
            curr_sum=0;
    }
    return max_sum;
}

int main(){
    vector<int> A = vector<int>(100,0);
    int num_ele;
    cin>>num_ele;
    for(int i=0;i<num_ele;i++){
        cin>>A[i];
    }
    cout<<maxSubArray(A)<<endl;
    return 0;
}

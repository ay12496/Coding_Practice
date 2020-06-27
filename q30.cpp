//Largest subarray with equal number of 0s and 1s (even or odd)
//number of subarrays with equal number of 0s and 1s (even or odd)

#include<bits/stdc++.h>
#define arr_len 20
using namespace std;

int main(){
    int arr[arr_len]={1,0,0,1,0,0,0,1,1,1,0,1,1,0,0,0,0,1,0,1};
    map<int,vector<int>> m = map<int, vector<int>>();
    int cum_sum_arr[arr_len] = {0}; //1 do +1, 0 do -1;
    int sum=0;
    if(arr[0])
        cum_sum_arr[0]=1;
    else
        cum_sum_arr[0]=-1;
    
    pair<int,vector<int>> p;
    p=pair<int,vector<int>>(cum_sum_arr[0],vector<int>({0}));
    m.insert(p);
    for(int i=1; i<arr_len; i++){
        if(arr[i]){
            cum_sum_arr[i]=cum_sum_arr[i-1]+1;
        }
        else{
            cum_sum_arr[i]=cum_sum_arr[i-1]-1;
        }
        if(m.find(cum_sum_arr[i])==m.end()){
            p=pair<int,vector<int>>(cum_sum_arr[i],vector<int>({i}));
            m.insert(p);
        }
        else
            m[cum_sum_arr[i]].push_back(i);
    }

    //first question
    int max_len=-1, len;
    int last_ele, first_ele, index;
    for(auto p: m){
        if(p.first==0){
            index = *(p.second.end()-1);
            len=index+1; //starting from 0;
            if(len>max_len){
                max_len=len;
            }
        }
        else{
            len = *(p.second.end()-1) - *(p.second.begin());
            if(len>max_len){
                max_len=len;
            }
        }
    }
    cout<<"Max Len: "<<max_len<<endl;

    //second question
    int num=0;
    for(auto p: m){
        if(p.first==0){
            num+=p.second.size();
        }
        num+=p.second.size()*(p.second.size()-1)/2;
    }
    cout<<"num of subarrays: "<<num<<endl;
    return 0;
}
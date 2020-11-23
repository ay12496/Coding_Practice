// 1/0 knapsack problem

#include<bits/stdc++.h>

using namespace std;

struct item{
    int val;
    int wt;
};

int main(){
    vector<item> item_list = vector<item>({{1,3},{2,5},{3,5},{3,4},{7,6},{2,4},{5,6},{8,8}});
    int max_wt=15;
    vector<int> before_best = vector<int>(max_wt+1,0);
    vector<int> curr = vector<int>(max_wt+1,0);
    cout<<" , "<<'\t';
    for(int j=0;j<=max_wt;j++)
        cout<<j<<'\t';
    cout<<endl;
    for(int i=0;i<item_list.size();i++){
        for(int j=1;j<=max_wt;j++){   
            if(j>=item_list[i].wt)
                curr[j] = (item_list[i].val + before_best[j-item_list[i].wt])>before_best[j] ? (item_list[i].val + before_best[j-item_list[i].wt]) : before_best[j];
            else
                curr[j] = before_best[j];
        }
        for(int j=1;j<=max_wt;j++){
            before_best[j]=curr[j];
        }
        cout<<item_list[i].val<<','<<item_list[i].wt<<'\t';
        for(int j=0;j<=max_wt;j++)
            cout<<curr[j]<<'\t';
        cout<<endl;
    }
    
    return 0;
}
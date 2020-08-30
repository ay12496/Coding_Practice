//Minimum deletions required to make frequency of each letter unique
#include<bits/stdc++.h>

using namespace std;
int matrix[1000][27];

int main(){
    // string s = "vitectpvrititutuetutututututututututttueororororowwwwwddddddddddldldldlldldldldldldldldldldldldldldldlmmmcmcmcmmcmcmcmcmcmcmcnfnnfndnf";
    string s = "geeksforgeeks";
    int arr[26]={0};
    for(char ch: s){
        arr[(int)ch-97]++;
    }
    memset(matrix,0, sizeof(1000*27));
    int max_count=0;
    for(int i=0;i<26;i++){
        if(arr[i]){
            // cout<<"char "<<(char)(i+97)<<" "<<arr[i]<<endl;
            max_count= max(max_count,arr[i]);
            matrix[arr[i]][matrix[arr[i]][26]]=i+97;   //0..25 --> 97..123 --> a..z
            matrix[arr[i]][26]++;
        }
    }

    // for(int i=1;i<=max_count;i++){
    //     cout<<"num of different char with count "<<i<<" : "<< matrix[i][26]<<"\t";
    //     for(int j=0;j<matrix[i][26];j++){
    //         cout<<(char)matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int i=max_count;
    int num_of_deleted_ele=0;
    while(i){
        if(matrix[i][26]>1){
            matrix[i-1][26]+=(matrix[i][26]-1);
            num_of_deleted_ele+=matrix[i][26]-1;
        }
        i--;
    }
    cout<<"num of deletion: "<<num_of_deleted_ele<<endl;
    return 0;
}
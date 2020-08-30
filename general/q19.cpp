#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="BAAAB";
    int arr[26+1]={0};
    for(auto ch: s){
        arr[(int)ch-65+1]++;
    }
    int odd=0;
    for(int i=1;i<=26;i++){
        if(arr[i]%2==1){
            odd++;
        }
    }
    if(odd==0)
        cout<<odd<<endl;
    else
        cout<<odd-1<<endl;
    return 0;
}
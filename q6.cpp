#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<char> s;
    int num;
    cin>>num;
    while(num!=0){
        int r=num%26;
        if(r==0){
            s.push('Z');
            num=num/26-1;
        }
        else{
            s.push((char)(r + 64));
            num=num/26;
        }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    // cin.getline(a,60);

    // for(char ch:a){

    // }
    return 0;
}
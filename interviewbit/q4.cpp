#include<bits/stdc++.h>

using namespace std;

string simplifyPath(string A) {
    string ans="";
    stack<string> s;
    int curr_pos=1; //ignoring first '/';
    int next_pos=A.find("/",curr_pos);
    string part;
    while(string::npos!= next_pos){
        part = A.substr(curr_pos, next_pos-curr_pos);
        if(part==".."){
            if(!s.empty())
                s.pop();
        }
        else if(part=="." || part==""){

        }
        else{
            s.push(part);
        }
        curr_pos=next_pos+1;
        next_pos=A.find("/",curr_pos);
    }
    
    part = A.substr(curr_pos, A.length());
    if(part==".."){
        if(!s.empty())
            s.pop();
    }
    else if(part=="." || part==""){

    }
    else{
        s.push(part);
    }
    
    while(!s.empty()){
        // cout<<s.top()<<endl;
        ans= "/"+ s.top() + ans;
        s.pop();
    }
    if(ans=="")
        ans="/";
    return ans;
}


int main(){
    cout<<simplifyPath("/a/./b/../../c/../..");
}
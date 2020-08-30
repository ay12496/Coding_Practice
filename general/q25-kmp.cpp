#include<bits/stdc++.h>
using namespace std;
int prefix_arr[1000]={0};
void gen_prefix_array(string str){
    int j=0,i = 1;
    prefix_arr[0]=-1;
    while(i<str.size()){
        if(str[i]==str[j]){
            prefix_arr[i]=j;
            j++;
            i++;
        }else{
            if(j!=0){
                j=prefix_arr[j-1];
                if(j==-1){
                    prefix_arr[i]=-1;
                    i++;
                }
                j++;
            }
            else{
                prefix_arr[i]=-1;
                i++;
            }
        }
        // for(int k=0;k<str.size();k++)
        //     cout<<prefix_arr[k]<<" ";
        // cout<<endl;
    }
}

int kmp(string substr,string str){
    gen_prefix_array(substr);
    int i=0,k=0;
    while(k<str.size()){
        if(substr[i]==str[k]){
            k++;
            i++;
        }
        else{
            if(i!=0){
                i=prefix_arr[i-1];
            }else{
                k++;
            }
        }
        if(i==substr.size()){
            cout<<k-substr.size()<<endl;
        }
        
    }
    return -1;
}

int main(){
    string str = "acacabacacabacacac", substr= "abaca";
    cout<<kmp(substr, str)<<endl;
    return 0;
}
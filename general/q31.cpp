//Given an array of 0s and 1s, and a number m, you can flip maximum m zeroes, count the maximum length of 1s you can make by flipping at max m zeroes.
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[]={1,0,0,1,0,0,0,1,1,1,0,1,1,0,0,0,0,1,1,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int wl=-1,wr=-1,nZero=0;
    int m=5;
    int nOne=0;
    int max_nOne=0;
    int max_l,max_r;
    while(wr!=size){
        if(!(nZero<=m)){
            while(arr[wl+1]==1 && wl<wr){
                nOne--;
                wl++;
            }
            if(arr[wl+1]==0){
                nZero--;
                wl++;
            }
        }else{
            if(wr+1!=size){
                if(arr[++wr]==0){
                    nZero++;
                }else{
                    nOne++;
                }
            }
            else{
                break;
            }

        }
        if(nOne>max_nOne){
            max_nOne = nOne;
            max_l=wl;
            max_r=wr;
        }
                
    }
    cout<<max_l<<" "<<max_r<<" "<<max_nOne+m<<endl;
    

    return 0;
}
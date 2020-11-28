//Get minimum element from stack
//https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

#include<bits/stdc++.h>

using namespace std;

class stack{
    vector<int> arr;
    vector<int> min_arr;
    int top;
public:
    stack(){
        top=-1;
    }

    void push(int num){
        if(arr.size()==top+1){
            arr.push_back(num);
            if(num<arr.top()){
                min_arr.push_back(num);
            }else{
                min_arr.push_back(arr.top());
            }
        }else{
            arr[top+1]=num;
            if(num<arr.top()){
                min_arr[top+1] = num;   
            }else{
                min_arr[top+1] = arr.top();
            }
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
    }
    int top(){
        if(top>=0){
            return arr[top];
        }
        return INT_MIN;
    }
    int getMin(){
        if(top>=0){
            return min_arr[top];
        }
        return INT_MIN;
    }
};


int main(){
    return 0;
}
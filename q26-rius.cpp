// recursion implemented through stack.
// firstly I will try factortial then fibanacci.
// solving recursively,then implementing the same with an iterative fn with stack

#include<bits/stdc++.h>

using namespace std;

int fac_rec(int num){
    int ret_ans=0;
    //start;
    if(num <=1)
        ret_ans = max(0,num);
    else
        ret_ans=num*fac_rec(num-1); //call
    //end
    return ret_ans;
}

struct state_variable{
    int num;
    int ret_ans;
};
int fac_iter(int num){
    stack<state_variable> num_s;
    enum{
        start,
        call,
        end
    };
    
    int state=start;
    int ret_ans=0;
    state_variable sv={0,0};
    sv.num = num;
    sv.ret_ans = 0;
    num_s.push(sv);
    do{
        switch(state){
            case start:
                sv = num_s.top();
                if(sv.num>1){
                    state = call;
                }else{
                    state_variable prev_sv = num_s.top();
                    num_s.pop();
                    prev_sv.ret_ans = 1;
                    num_s.push(prev_sv);
                    state = end;
                }
                break;
            case call:
                num_s.push({sv.num-1,0});
                state = start;
                break;
            case end:
                sv = num_s.top(); //restoring prev state variable
                num_s.pop();
                if(!num_s.empty()){
                    state_variable prev_sv = num_s.top();
                    num_s.pop();    
                    prev_sv.ret_ans = sv.num*sv.ret_ans;
                    num_s.push(prev_sv);
                    state=end; 
                }else{
                    break;
                }
        }
    }while(!num_s.empty());
    return sv.num*sv.ret_ans;
}



int fib_rec(int pos){
    if(pos == 1 || pos == 0)
        return pos;
    return fib_rec(pos-1) + fib_rec(pos-2);
}

int fib_iter(int pos){
    stack<int> pos_s; 
    stack<int> val_s;
    while(1){
        int prev_pos = pos-1;
        int prev_prev_pos = pos - 2;
        while(pos>1){
            pos_s.push(pos - 1);
            pos_s.push(pos - 2);
            pos=pos_s.top();
            pos_s.pop();
        }
    }
}

int main(){
    for(int i=1;i<10;i++)
        cout<<i<<" "<<fac_iter(i)<<endl;
    return 0;
}
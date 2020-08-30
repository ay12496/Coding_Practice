//infixtopostfix
//infixtoprefix
//calculatepostfix
//calculateprefix

#include<bits/stdc++.h>
using namespace std;

int prec(char ch){
    switch(ch){
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '-':
        case '+': return 1;
        default: return -1;
    }
}

string infixToPostfix(string exp){
    stack<char> s;
    string ans;
    for(auto ch: exp){
        if(ch=='+' || ch=='*' || ch=='/' || ch=='-' || ch=='^'){
            if(!s.empty()){
                while(prec(s.top())>=prec(ch) &&  s.top()!='(' && s.top()!=')'){
                    ans+=s.top();
                    s.pop();
                    if(s.empty())
                        break;
                }
                s.push(ch);
            }else{
                s.push(ch);
            }
        }
        else if (ch=='('){
            s.push(ch);      
        }
        else if (ch==')'){
            while(s.top()!='(' && s.empty()!=true){
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            ans+=ch;
        }
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}

string infixToPrefix(string exp){
    //Here we do the same as postfix but reading or scaning is done is reverse order from right to left
    stack<char> s;
    string ans;
    for(int i=exp.size()-1;i>=0;i--){
        char ch=exp[i];
        if(ch=='+' || ch=='*' || ch=='/' || ch=='-' || ch=='^'){
            if(!s.empty()){
                while(prec(s.top())>=prec(ch) &&  s.top()!='(' && s.top()!=')'){
                    ans=s.top() + ans;
                    s.pop();
                    if(s.empty())
                        break;
                }
                s.push(ch);
            }else{
                s.push(ch);
            }
        }
        else if (ch==')'){ // ')': opening brace as reading from right to left in reverse order
            s.push(ch);      
        }
        else if (ch=='('){ // '(': closing brace as reading from left to right in reverse order
            while(s.top()!=')' && s.empty()!=true){ 
                ans=s.top()+ans;
                s.pop();
            }
            s.pop();
        }
        else{
            ans=ch+ans;
        }
    }
    while(!s.empty()){
        ans=s.top() + ans;
        s.pop();
    }
    return ans;
}


long long calc_postfix_exp(string exp){
    long long res;
    stack<long long> s;
    for(auto ch: exp){
        if(ch=='*' || ch=='+' || ch=='-' || ch=='^'){
            long long num1, num2;
            if(!s.empty()){
                num1 = s.top();
                s.pop();
            }
            else{
                cout<<"failed"<<endl;
                return INT_MIN;
            }
            if(!s.empty()){
                num2 = s.top();
                s.pop();
            }
            else{
                cout<<"failed"<<endl;
                return INT_MIN;
            }
            switch(ch){
                case '+': num2+= num1;
                    break;
                case '-': num2-= num1;
                    break;
                case '*': num2*= num1;
                    break;
                case '^': num2= pow(num2,num1);
                    break;
                default :
                    cout<<"failed"<<endl;
                    return INT_MIN;
            }
            s.push(num2);
        }
        else{
            s.push((long long)ch - 97);
        }
    }
    if(!s.empty()){
        res = s.top();
        s.pop();
    }
    if(s.empty())
        return res;
    else{
        cout<<"failed"<<endl;
        return INT_MIN;
    }
}

long long calc_prefix_exp(string exp){
    long long res;
    stack<long long> s;
    for(int i=exp.size()-1;i>=0;i--){  //reverse evaluation
        char ch= exp[i];     
        if(ch=='*' || ch=='+' || ch=='-' || ch=='^'){
            long long num1, num2;
            if(!s.empty()){
                num1 = s.top();
                s.pop();
            }
            else{
                cout<<"failed"<<endl;
                return INT_MIN;
            }
            if(!s.empty()){
                num2 = s.top();
                s.pop();
            }
            else{
                cout<<"failed"<<endl;
                return INT_MIN;
            }
            switch(ch){
                case '+': num1+= num2;
                    break;
                case '-': num1-= num2;
                    break;
                case '*': num1*= num2;
                    break;
                case '^': num1= pow(num1,num2);
                    break;
                default :
                    cout<<"failed"<<endl;
                    return INT_MIN;
            }
            s.push(num1);
        }
        else{
            s.push((long long)ch - 97);
        }
    }
    if(!s.empty()){
        res = s.top();
        s.pop();
    }
    if(s.empty())
        return res;
    else{
        cout<<"failed"<<endl;
        return INT_MIN;
    }
}


int main(){
    string exp = "a+b*(b^d-e)^(f+b*h)-i"; //here let assume a..z means --> 0..25 
    cout<<"infix:  \t"<<exp<<endl;
    string postfix_exp = infixToPostfix(exp);
    cout<<"postfix:\t"<<postfix_exp<<endl;
    cout<<"calc postfix exp:\t"<<calc_postfix_exp(postfix_exp)<<endl;
    string prefix_exp = infixToPrefix(exp);
    cout<<"prefix: \t"<<prefix_exp<<endl; 
    cout<<"calc prefix exp:\t"<<calc_prefix_exp(prefix_exp)<<endl;
    return 0;
}
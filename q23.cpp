// Rearrange characters in a string such that no two adjacent characters are same (Priority Queue)
#include<bits/stdc++.h>
using namespace std;

class Key{
public:    
    char alpha;
    int freq;
    Key(char alpha, int freq){
        this->alpha = alpha;
        this->freq = freq;
    }
    bool operator<(const Key &ele) const {
        return freq < ele.freq;
    }
};

string rearrangeString(string str){
    string ans="";
    int a_freq[26]={0};

    for(auto ch: str){
        a_freq[(int)ch-65]++;
    }

    priority_queue<Key> pq;
    for(int i=0;i<26;i++){
        if(a_freq[i]){
            pq.push(Key((char)(i+65),a_freq[i]));
        }
    }
    auto prev = Key('#',-1);
    while (!pq.empty()){ 
        auto temp = pq.top();
        pq.pop();
        ans =  ans + temp.alpha;
        //cout<<ans<<endl;
        temp.freq--;
        if(prev.freq>0)
            pq.push(prev);
        prev.alpha = temp.alpha;
        prev.freq = temp.freq;

    }
    return ans;
}

int main(){
    string str = "BBBAA" ; 
    cout<<rearrangeString(str)<<endl; 
    return 0;
}
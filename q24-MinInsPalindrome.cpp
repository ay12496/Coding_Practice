//Minimum insertions to form a palindromeq24    
#include<bits/stdc++.h>
using namespace std;

int table[1024][1024];
int count = 0;

int minInsertion(string str, int l, int h){
    int ans=0;
    if (table[l][h] !=-1) // table being used for memoisation.
        return table[l][h];
    
    if (l==h)
        ans = 0;
    else if (h-l==1)
        ans = str[l]==str[h] ? 0 : 1;
    else if(str[l]==str[h])
        ans = minInsertion(str, l+1, h-1);
    else
        ans = min(minInsertion(str, l, h-1), minInsertion(str, l+1, h)) + 1;
    ::count++;
    table[l][h] = ans;
    return ans;
}

int main(){
    vector<string> str_list= {"ab","aa","abc","abcd","abcda","abcde"};
    for(auto s: str_list){
        ::count=0; // count here to display how it usng table for memonisation.
        memset(table, -1, sizeof(table));
        cout<<minInsertion(s, 0, s.length()-1);
        cout<<"\t"<<::count<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define MAX_LENGTH 1024
typedef string* string_pointer;

int l[MAX_LENGTH+1][MAX_LENGTH+1];
string* string_mat[MAX_LENGTH+1][MAX_LENGTH+1];
string empty = "";

void lcs(string str1, string str2){
    string_pointer* string_ptr_ptr  = new string_pointer[MAX_LENGTH*MAX_LENGTH];
    int count=-1;

    for(int i=0;i<=str1.length();i++){
        l[i][str2.length()] = 0;
        string_mat[i][str2.length()]  = &empty;
    }
    for(int i=0;i<=str2.length();i++){
        l[str1.length()][i] = 0;
        string_mat[str1.length()][i]  = &empty;
    }

    for(int i=str1.length()-1;i>=0;i--){
        for(int j=str2.length()-1;j>=0;j--){
            if(str1[i]==str2[j]){
                l[i][j] = l[i+1][j+1] + 1;
                string* substr = new string();
                substr->append(1,str1[i]);
                *substr = *substr + *string_mat[i+1][j+1];
                string_mat[i][j] = substr;
                string_ptr_ptr[++count] = substr;
            }
            else{
                if(l[i+1][j]< l[i][j+1]){
                    string_mat[i][j] = string_mat[i][j+1];
                    l[i][j] = l[i][j+1];
                }
                else{
                    string_mat[i][j] = string_mat[i+1][j];
                    l[i][j] = l[i+1][j];
                }
            }
        }   
    }
    cout<<l[0][0]<<endl;

    while(count>=0){
        delete string_ptr_ptr[count--];
    }
    delete[] string_ptr_ptr;
}


int main(){
    while(1){
        string str1 = "fdsfdssfsddsafrwdrwdr";
        string str2 = "fsdfwrdd";
        lcs(str1, str2);
    }
    return 0;
}
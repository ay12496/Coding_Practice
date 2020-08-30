#include<bits/stdc++.h>

using namespace std;

struct segment{
    int start;
    int end;
    int min_value;
};

class segment_tree{
    vector<segment> t;
public:
    void tree_init_traversal(int index, int arr[]){
        int mid=(t[index].start+t[index].end)/2;
        t[2*index + 1] = {t[index].start, mid,0}; //Child_1 = 2*Parent+1
        if(t[2*index+1].start != t[2*index+1].end) //range is more than 1.
            tree_init_traversal(2*index + 1, arr);
        else
            t[2*index+1].min_value = arr[t[2*index + 1].start];

        t[2*index + 2] = {mid + 1, t[index].end, 0}; //Child_2 = 2*Parent+2
        if(t[2*index+2].start != t[2*index+2].end) //range is more than 1.
            tree_init_traversal(2*index + 2, arr);
        else
            t[2*index+2].min_value = arr[t[2*index + 2].start];
        
        t[index].min_value=min(t[2*index+1].min_value,t[2*index+2].min_value);
    }

    void build_tree(int arr[], int size){
        t = vector<segment>();
        int i=1;
        while(size>=pow(2,i))
            i++;
        t.resize(2*pow(2,i)+1);
        t[0]={0,size-1, 0};
        tree_init_traversal(0, arr);
    }

    void traverse_update_at(int curr_index, int update_index, int value){
        if(t[curr_index].start == t[curr_index].end){
            //leaf node
            if(t[curr_index].start==update_index){
                t[curr_index].min_value = value;
                return;
            }
        }
        else{
            //internel node
            if(t[2*curr_index + 1].start <= update_index && t[2*curr_index + 1].end >= update_index){
                traverse_update_at(2*curr_index+1, update_index, value);
            }
            else if(t[2*curr_index + 2].start <= update_index && t[2*curr_index + 2].end >= update_index){
                traverse_update_at(2*curr_index+2, update_index, value);
            }
        }
        t[curr_index].min_value=min(t[2*curr_index+1].min_value,t[2*curr_index+2].min_value);
    }

    void update_at(int update_index, int value){
        traverse_update_at(0, update_index, value);    
    }

    int find_min(int index){
        int tree_index=0;
        while(t[tree_index].start!=t[tree_index].end){
            if(index>=t[2*tree_index + 1].start && index<=t[2*tree_index + 1].end)
                tree_index = 2*tree_index + 1;
            else if(index>=t[2*tree_index + 2].start && index<=t[2*tree_index + 2].end)
                tree_index = 2*tree_index + 2;
        }
        if(t[tree_index].start==index)
            return t[tree_index].min_value;        
    }
};

int main(){
    int arr[8]={3,6,1,8,4,9,0,10};
    segment_tree st;
    st.build_tree(arr, 6);
    for(int i=0;i< 6;i++){
        cout<<i<<" "<<st.find_min(i)<<endl;
    }
    cout<<"update"<<endl;
    st.update_at(2, 5);
    for(int i=0;i< 6;i++){
        cout<<i<<" "<<st.find_min(i)<<endl;
    }
    return 0;
}
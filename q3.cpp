#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class vertex{
public:    
    int value;
    vector<int> out_edge;

    vertex(int value, vector<int> out_edge){
        this->value = value;
        this->out_edge = out_edge;
    }
};

class graph{
public:
    vector<vertex> adj_list;
};

void dfs(graph g, int v, stack<int>* s, int visited[]){
    for(auto next_vertex: g.adj_list[v-1].out_edge){
        if(visited[next_vertex]==0){
            visited[next_vertex]=1;
            dfs(g,next_vertex,s,visited);
        }
    }
    s->push(v);
    //cout<<v<<' ';
}

stack<int>* topological(graph g){
    stack<int>* s =  new stack<int>();
    int visited[g.adj_list.size()+1];
    for(int i=0;i<g.adj_list.size()+1;i++){
        visited[i]=0;
    }
    for(auto v: g.adj_list){
        if(visited[v.value]==0){
            visited[v.value]=1;
            dfs(g,v.value,s,visited);
        }
    }
    return s;
}

int main(){
    graph A;
    A.adj_list.push_back({1,{2,3}});
    A.adj_list.push_back({2,{}});
    A.adj_list.push_back({3,{6}});
    A.adj_list.push_back({4,{2,5}});
    A.adj_list.push_back({5,{}});
    A.adj_list.push_back({6,{5}});
    stack<int>* s = topological(A);
    while(!s->empty()){
        cout<<s->top()<<" ";
        s->pop();
    }

    // for(auto v:A.adj_list){
    //     for(auto oe:v.out_edge){
    //         cout<<oe<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
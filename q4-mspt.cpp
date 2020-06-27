#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class edge{
public:
    int weight;
    int start;
    int end;
    bool operator <(const edge &a){
        return weight < a.weight;
    }
};

class Graph{
public:
    int num_vertex;
    int num_edge;
    list<edge> edge_list;
    Graph(int num_vertex, int num_edge){
        this->num_vertex= num_vertex;
        this->num_edge = num_edge;
        this->edge_list = list<edge>();
    }
    
};

int parent[100];
int findparent(int vertex){
    if(parent[vertex]==vertex){
        return vertex;
    }
    return findparent(parent[vertex]);

}


list<edge> kruskal(Graph* g){
    list<edge> edge_list;
    g->edge_list.sort();
    int vertex_count=0;
    int visited[g->num_vertex];
    for(auto edge :g->edge_list){
        if(findparent(edge.start)==findparent(edge.end)){
            //cycle skip
            continue;
        }
        parent[findparent(edge.end)] = findparent(edge.start);
        edge_list.push_back(edge);
    }
    return edge_list;
}

int main(){
    for(int i=0;i<9;i++){
        parent[i]=i;
    }
    Graph* g = new Graph(9,14);
    list<edge>::iterator it = g->edge_list.begin();
    g->edge_list.push_back({2,8,2});
    g->edge_list.push_back({10,5,4});
    g->edge_list.push_back({1,7,6});
    g->edge_list.push_back({4,2,5});
    g->edge_list.push_back({6,8,6});
    g->edge_list.push_back({7,7,8});
    g->edge_list.push_back({4,0,1});
    g->edge_list.push_back({8,0,7});
    g->edge_list.push_back({11,1,7});
    g->edge_list.push_back({9,3,4});
    g->edge_list.push_back({2,6,5});
    g->edge_list.push_back({14,3,5});
    g->edge_list.push_back({8,1,2});
    g->edge_list.push_back({7,2,3});
    list<edge> edge_list = kruskal(g);
    for(auto edge: edge_list){
        cout<<edge.weight<<"\t"<<edge.start<<"\t"<<edge.end<<endl;
    }
    return 0;
}
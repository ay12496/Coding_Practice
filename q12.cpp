#include <bits/stdc++.h>

using namespace std;
// Number of vertices in the graph 
#define V 9 

int dis[V]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
int path[V]={-1,-1,-1,-1,-1,-1,-1,-1,-1};

void dijkstra(int graph[][V], int start){
    vector<int> l;
    l.push_back(start);
    path[start]=start;
    dis[start]=0;
    int from=0;
    while(!l.empty()){
        int min=INT_MAX;
        auto it = l.begin();
        int pos=0;
        for(int i=0;i<l.size();i++){
            if(dis[l.at(i)]<min){
                from=l.at(i);
                min=dis[from];
                pos=i;
            }
        }
        l.erase(it+pos);
        for(int i=0;i<V;i++){
            if(graph[from][i]!=0){
                if(dis[i]==-1){
                    dis[i] = graph[from][i] + dis[from];
                    path[i] = from;
                    l.push_back(i);
                }
                else if(dis[i]>graph[from][i] + dis[from]){
                    dis[i] = graph[from][i] + dis[from];
                    path[i] = from;
                }
            }
        }
    }
    cout<<"i\tdis\tpath"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<'\t'<<dis[i]<<'\t'<<path[i]<<endl;
    }
}

int main(){
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
    return 0;
}
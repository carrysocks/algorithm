#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph{
public:
    int size;
    vector<vector<int>> adj;
    vector<bool> visited;
    
    Graph(int n){
        size=n;
        adj.resize(n);
        visited.resize(n);
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //dfs order to lower number 
    //낮은 숫자순으로 
    void sortList(){
        for(int i=0;i<size;i++)
            sort(adj[i].begin(),adj[i].end());
    }
    
    void dfs(int here){
        cout<<"Node"<<here<<"visited"<<'\n';
        visited[here]=true;
        for(int i=0;i<adj[here].size();i++){
            int there = adj[here][i];
            
            if(!visited[there])
                dfs(there);
        }
    }
    
    void dfsAll(){
        visited = vector<bool>(adj.size(),false);
        for(int i=0;i<adj.size();i++)
            if(!visited[i])
                dfs(i);
    }
};

int main(){
    Graph G(9);
    //graph insert
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,3);
    G.addEdge(1,5);
    G.addEdge(3,4);
    G.addEdge(4,5);
    G.addEdge(2,6);
    G.addEdge(2,8);
    G.addEdge(6,8);
    G.addEdge(6,7);
    G.sortList();
    G.dfsAll();
}

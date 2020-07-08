#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
public:
    int size;
    vector<vector<int>> adj;
    vector<bool> visited;
    queue<int> q;
    vector<int> order;
    
    Graph(int n){
        size=n;
        adj.resize(n);
        visited.resize(n);
        order.resize(n);
    }
    
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void sortList(){
        for(int i=0;i<size;i++)
            sort(adj[i].begin(),adj[i].end());
    }
    
    vector<int> bfs(int start){
        
        visited = vector<bool>(size,false);
        visited[start]=true;
        q.push(start);
        order.push_back(start);
        
        while(!q.empty()){
            int here = q.front();
            q.pop();
            
            for(int i=0;i<adj[here].size();i++){
                int there=adj[here][i];
                if(!visited[there]){
                    q.push(there);
                    visited[there]=true;
                }
            }
        }
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
    G.bfs(0);
}

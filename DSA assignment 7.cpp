#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<pair<int,int>>> adj;
    
    Graph(int V){
        this->V=V;
        adj.resize(V);
    }
    
    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        
    }
    
    int prim(){
        vector<bool> visited(V);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        //E log E
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int adjnode=it.first;
            int wt=it.second;
            if(visited[adjnode]) continue;
            visited[adjnode]=1;
            sum+=wt;
            
            for(auto i:adj[adjnode]){ //E logE
                int n=i.first;
                int w=i.second;
                if(!visited[n]){
                    pq.push({n,w});
                }
            }
        }
        return sum;
    }

};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    
    cout<<g.prim()<<endl;

    return 0;
}


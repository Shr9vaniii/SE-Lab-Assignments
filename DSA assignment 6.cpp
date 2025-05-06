#include <bits/stdc++.h>
using namespace std;

void createadj( unordered_map<int,vector<int>> &mp,vector<vector<int>> edge){
    for(auto it:edge){
        int u=it[0];
        int v=it[1];

        mp[u].push_back(v);
        mp[v].push_back(u);
    }
}

vector<int> bfs(unordered_map<int,vector<int>> &mp,int n,int v){
    vector<int> ans;
    vector<bool> visited(v,0);

    visited[n]=1;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it:mp[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }

    }
    return ans;
}

void dfs(unordered_map<int,vector<int>> mp,int n,vector<bool> &visited,vector<int> &ans)
{
    
    visited[n]=1;
    ans.push_back(n);
    
    for(auto it:mp[n]){
        if(!visited[it]){
            dfs(mp,it,visited,ans);
        }
    }
    
}


int main(){
    vector<vector<int>> edge={{0,3},{0,1},{1,3},{1,2},{2,4}};

    unordered_map<int,vector<int>> mp;
    createadj(mp,edge);
    vector<int> ans=bfs(mp,0,5);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    vector<bool> visited(5);
    vector<int> ans1;
    cout<<"dfs: "<<endl;
    dfs(mp,0,visited,ans1);
    for(int i=0;i<ans1.size();i++){
        cout<<ans[i]<<" ";
        
    }cout<<endl;
    


}

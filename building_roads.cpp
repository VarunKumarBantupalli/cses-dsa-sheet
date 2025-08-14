#include <bits/stdc++.h>
using namespace std;

void dfs(int node , vector<int>& visited , vector<int>adj[]){


    visited[node] = 1;

    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it,visited,adj);
        }
    }
}

int main(){
    int m; //no.of cities
    int n; //no.of roads

    cin>>m;
    cin>>n;

    vector < int> adj[m+1];

    for(int i = 0 ; i < n ; i++){
        int u ,v;

        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>visited(m+1 ,0);
    vector<int>reps;

    for(int i = 1 ;i <= m ;i++){
        if(!visited[i]){
            dfs(i , visited ,adj);
            reps.push_back(i);
        }
    }

    cout<<reps.size()-1<<endl;

    for(int i = 0 ; i < reps.size()-1 ;i++){
        cout<<reps[i]<<" "<<reps[i+1]<<endl;
    }

}
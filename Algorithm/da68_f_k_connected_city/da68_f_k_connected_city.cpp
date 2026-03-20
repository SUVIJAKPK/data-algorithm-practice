#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> adj(N + 1);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    vector<int> dist(N + 1, -1);
    queue<int> q;

    q.push(1);
    dist[1] = 0;

    while(!q.empty() && ans.size() < K){
        int u = q.front();
        q.pop();

        ans.push_back(u);
        if(ans.size() == K) break;

        for(auto e : adj[u]){
            if(dist[e] == -1){
                dist[e] = dist[u] + 1;
                q.push(e);
            }
        }
    }

    for(auto t : ans) cout << t << " ";
}
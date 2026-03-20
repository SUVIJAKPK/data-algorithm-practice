#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, E, K;
    cin >> N >> E >> K;
 
    vector<vector<int>> adj(N);
    for(int i = 0; i < E; i++){
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int answer = 0;

    for(int i = 0; i < N; i++){
        vector<int> dist(N,-1);
        queue<int> q;

        q.push(i);
        dist[i] = 0;

        int cnt = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(dist[u] == K) continue;

            for(int v : adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    if(dist[v] <= K) cnt++;
                    q.push(v);
                }
            }
            answer = max(answer, cnt);
        }
    }

    cout << answer;
}
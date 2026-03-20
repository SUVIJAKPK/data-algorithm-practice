#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v;
    long long w;
};

vector<int> dist(100000);

int findset(int x){
    if(dist[x] == x) return x;
    dist[x] = findset(dist[x]);
    return dist[x];
}

void unionx(int x, int y){
    int s1 = findset(x);
    int s2 = findset(y);
    dist[s1] = s2;
}

int main(){
    int N, M, U, K;
    cin >> N >> M >> U >> K;

    vector<edge> adj;
    for(int i = 0; i < M; i++){
        int u, v, d;
        cin >> u >> v >> d;
        adj.push_back({u, v, 1LL * d * U});
    }

    sort(adj.begin(), adj.end(), [](edge a, edge b){
        return a.w < b.w;
    });

    for(int i = 0; i <= N; i++) dist[i] = i;

    long long ans = 0;
    int comp = N;

    for(auto e : adj){
        if(findset(e.u) != findset(e.v)){
            unionx(e.u, e.v);
            ans += e.w;
            comp--;

            if(comp == K) break;
        }
    }

    cout << ans;
}
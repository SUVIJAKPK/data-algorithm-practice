#include <bits/stdc++.h>
using namespace std;

bool kuhn(int u, vector<vector<int>> &adj, vector<int> &matchR, vector<int> &vis) {
    if (vis[u]) return false;
    vis[u] = 1;

    for (int v : adj[u]) {
        if (matchR[v] == -1 || kuhn(matchR[v], adj, matchR, vis)) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<int> p(m), h(m), t(k);
    for (int i = 0; i < m; i++) cin >> p[i];
    for (int i = 0; i < m; i++) cin >> h[i];
    for (int i = 0; i < k; i++) cin >> t[i];

    long long totalHealth = 0;
    for (int x : h) totalHealth += x;

    // สร้าง slot ของ monster
    vector<int> slotMonster;  // slotMonster[s] = monster index
    for (int i = 0; i < m; i++) {
        int cnt = min(h[i], k);   // เกินนี้ก็ไม่มีป้อมพอยิงอยู่ดี
        for (int c = 0; c < cnt; c++) {
            slotMonster.push_back(i);
        }
    }

    int S = (int)slotMonster.size();

    // adj[u] = slots ที่ป้อม u ยิงได้
    vector<vector<int>> adj(k);
    for (int u = 0; u < k; u++) {
        for (int s = 0; s < S; s++) {
            int mon = slotMonster[s];
            if (abs(t[u] - p[mon]) <= w) {
                adj[u].push_back(s);
            }
        }
    }

    // maximum bipartite matching
    vector<int> matchR(S, -1);
    int maxDamage = 0;

    for (int u = 0; u < k; u++) {
        vector<int> vis(k, 0);
        if (kuhn(u, adj, matchR, vis)) {
            maxDamage++;
        }
    }

    cout << (totalHealth - maxDamage) << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> adj[20];
int K[8];
bool ans[8];
int maxK;

void dfs(int start,int u,int mask,int sum,int depth,
         unordered_set<int> &S){

    if(sum>maxK) return;

    S.insert(sum);

    if(depth==10) return;

    for(auto &e:adj[u]){
        int v=e.first;
        int w=e.second;

        if(mask&(1<<v)) continue;

        dfs(start,v,mask|(1<<v),sum+w,depth+1,S);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    for(int i=0;i<8;i++){
        cin>>K[i];
        maxK=max(maxK,K[i]);
    }

    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;

        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    for(int start=0;start<n;start++){

        unordered_set<int> S;

        dfs(start,start,1<<start,0,0,S);

        for(int i=0;i<8;i++){
            if(S.count(K[i])) ans[i]=true;
        }
    }

    for(int i=0;i<8;i++)
        cout<<(ans[i]?"YES":"NO")<<"\n";
}
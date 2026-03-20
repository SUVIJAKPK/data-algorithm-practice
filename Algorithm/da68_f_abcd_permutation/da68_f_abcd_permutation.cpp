#include <bits/stdc++.h>
using namespace std;

int N, a, b, c, d;
vector<string> ans;

void permu(string cur, int aa, int bb, int cc, int dd){
    if(cur.size() == N){
        ans.push_back(cur);
        return;
    }

    if(aa < a) permu(cur + 'A', aa + 1, bb, cc, dd);
    if(bb < b) permu(cur + 'B', aa, bb + 1, cc, dd);
    if(cc < c) permu(cur + 'C', aa, bb, cc + 1, dd);
    if(dd < d) permu(cur + 'D', aa, bb, cc, dd + 1);
}

int main(){
    cin >> N >> a >> b >> c >> d;

    permu("",0,0,0,0);

    cout << ans.size() << endl;
    for(auto an : ans){
        cout << an << endl;
    }
}
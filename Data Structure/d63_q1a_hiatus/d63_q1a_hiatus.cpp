#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> hiatus;
    while(n--){
        int a, b;
        cin >> a >> b;
        hiatus.insert({a,b});
    }

    while(m--){
        int year, month;
        cin >> year >> month;
        pair<int,int> q = {year, month};

        if(hiatus.find(q) != hiatus.end()){
            cout << 0 << " " << 0 << " ";
            continue;
        }

        auto itr = hiatus.lower_bound(q);
        if(itr == hiatus.begin()){
            cout << -1 << " " << -1 << " ";
            continue;
        }
        itr--;
        cout << itr->first << " " << itr->second << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

set<pair<int , int>> line;

void buy_line(int a , int b){
    if(line.empty()){
        line.insert({a , b});
        return;
    } 

    auto it = line.lower_bound({a , -1});

    // 3 4
    // 5 6
    if(it != line.begin()){
        auto prev = it;
        prev--;
        if(prev->second >= a - 1) it = prev;
    }

    int low = a , high = b;

    while(it != line.end() && it->first <= high + 1){
        low = min(low , it->first);
        high = max(high , it->second);
        it = line.erase(it);
    }

    line.insert({low,high});
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    while(n--){
        int select; cin >> select;
        if(select == 1){
            int a , b; cin >> a >> b;
            buy_line(a , b);
        }else if(select == 2){
            cout << line.size() << "\n";
            // for(auto o : line) cout << o.first << " " << o.second << endl;
        }
    }

}
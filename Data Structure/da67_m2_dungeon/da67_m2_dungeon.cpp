#include <bits/stdc++.h>
using namespace std;


int main(){
    int n , d , t , z; cin >> n >> d >> t >> z;

    map<int , priority_queue<int,vector<int>,greater<int>>> dungeon;
    while(d--){
        int t , z;
        cin >> t >> z;
        dungeon[z].push(t);
    }

    int kill = 0;
    while(n--){
        int q; cin >> q;
        int hp = t;
        bool no_item = false;
        while(q--){
            int item; cin >> item;
            if(!dungeon[item].empty() && dungeon[item].top() <= hp){
                hp -= dungeon[item].top();
                dungeon[item].pop();
            }else{
                cout << kill;
                return 0;
            }
        }

        if(!no_item && (hp >= 0)){
            kill++;
            t = hp;
        }else{
            cout << kill;
            return 0;
        }
    }

    cout << kill;
}
#include <bits/stdc++.h>
using namespace std;

void game_zuma(list<int> &v , int pos , int color){
    auto pos_itr = v.begin();
    for(int i = 0; i < pos; i++) pos_itr++;
    auto itr = v.insert(pos_itr , color);
    while(v.size() >= 3){
        int count = 1;
        color = *itr;

        // Counting Left
        auto left = itr;
        while(left != v.begin()){
            auto prev_it = prev(left);
            if(*prev_it == color){
                left = prev_it;
                count++;
            }
            else break;
        }

        // Counting Right
        auto right = itr;
        while(right != v.end()){
            auto next_it = next(right);
            if(*next_it == color){
                right = next_it;
                count++;
            }
            else break;
        }

        if(count >= 3){
            auto nextpos = v.erase(left , next(right));
            if(v.empty()) return;
            itr = nextpos;
            if(*itr != *(prev(itr))) break;
        }else break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , k , v; cin >> n >> k >> v;
    list<int> zuma;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        zuma.push_back(m);
    }

    game_zuma(zuma , k , v);

    for(auto a : zuma) cout << a << " ";

}
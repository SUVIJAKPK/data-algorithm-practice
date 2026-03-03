#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec_n(n), ans;

    for(int i = 0; i < n; i++) cin >> vec_n[i];

    sort(vec_n.begin(), vec_n.end());

    for(int i = 0; i < m; i++){
        int num; 
        cin >> num;
        
        int lower = num - k, high = num + k;

        auto it_lower = lower_bound(vec_n.begin(), vec_n.end(), lower);
        auto it_high = upper_bound(vec_n.begin(), vec_n.end(), high);
        
        ans.push_back(it_high - it_lower);
    }

    for(auto aa : ans) cout << aa << " ";
}
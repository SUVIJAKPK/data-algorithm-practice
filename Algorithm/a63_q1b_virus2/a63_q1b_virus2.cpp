#include <bits/stdc++.h>
using namespace std;

bool check_virus(vector<int> &v, int l, int r){
    int len = r - l + 1;
    
    if(len == 2) return true;
    
    int mid = (l + r) / 2;

    bool left_ok = check_virus(v, l, mid);
    bool right_ok = check_virus(v, mid + 1, r);

    if(!left_ok || !right_ok) return false;

    int count_left = 0, count_right = 0;
    for(int i = l; i <= mid; i++) count_left += v[i];
    for(int i = mid + 1; i <= r; i++) count_right += v[i];

    return abs(count_left - count_right) <= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int sz = 1 << k;

    while (n--) {
        vector<int> v(sz);
        for (int i = 0; i < sz; i++) cin >> v[i];

        cout << (check_virus(v, 0, sz - 1) ? "yes" : "no") << endl;
    }
}
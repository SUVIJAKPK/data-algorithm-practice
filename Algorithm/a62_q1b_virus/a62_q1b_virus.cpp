#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int>& v, int l, int r) {
    int len = r - l + 1;

    // base case: length 2
    if (len == 2) {
        return (v[l] == 0 && v[l + 1] == 1);
    }

    int mid = (l + r) / 2;

    // right half must be valid
    if (!check(v, mid + 1, r)) return false;

    // left half valid as-is
    if (check(v, l, mid)) return true;

    // left half valid after reverse?
    vector<int> revLeft;
    for (int i = mid; i >= l; --i) {
        revLeft.push_back(v[i]);
    }

    return check(revLeft, 0, (int)revLeft.size() - 1);
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

        if (check(v, 0, sz - 1)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
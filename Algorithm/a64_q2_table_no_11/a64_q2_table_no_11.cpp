#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long dp00 = 1, dp01 = 1, dp10 = 1;

    for(int i = 2; i <= n; i++){
        long long new00 = (dp00 + dp01 + dp10) % 100000007;
        long long new01 = (dp00 + dp10) % 100000007;
        long long new10 = (dp00 + dp01) % 100000007;

        dp00 = new00;
        dp01 = new01;
        dp10 = new10;
    }

    long long ans = (dp00 + dp01 + dp10) % 100000007;
    cout << ans;
}
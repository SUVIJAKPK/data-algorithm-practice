#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,m,k;
    cin >> n >> m >> k;

    vector<ll> A(n), pref(n + 1, 0);;
    for(int i = 0; i < n; i++){
        int rr;
        cin >> A[i];
        pref[i + 1] = pref[i] + A[i];
    }
    
    while(m--){
        ll a,b;
        cin >> a >> b;
        
        int l = a, r = n-1, ans = a-1;

        while(l <= r){
            int mid = (l+r)/2;

            ll grass = pref[mid + 1] - pref[a];
            ll len = mid - a + 1;
            ll cost = grass + len*k;

            if(cost <= b){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        if(ans < a){
            cout << 0 << endl;
        }else{
            cout << pref[ans + 1] - pref[a] << endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<ll,ll> family; // {son,father}

bool check_grandfather(ll A, ll B){
    if(A == B) return false;
    if(!family.count(A) || !family.count(B)) return false;
    if(!family.count(family[A]) || !family.count(family[B])) return false;
    if(family[family[A]] == family[family[B]]) return true;
    return false;
}

int main(){
    ll N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        ll F, S;
        cin >> F >> S;
        family[S] = F;
    }

    vector<bool> ans; 
    for(int i = 0; i < M; i++){
        ll A, B;
        cin >> A >> B;
        ans.push_back(check_grandfather(A,B));
    }

    for(auto aa : ans){
        cout << ((aa) ? "YES" : "NO") << endl;
    }
}
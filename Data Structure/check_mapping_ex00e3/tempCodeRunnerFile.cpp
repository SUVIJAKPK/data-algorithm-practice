#include <bits/stdc++.h>
using namespace std;

bool check_mapping(vector<int> v){
    for(int i = 1; i <= v.size(); i++){
        if(i != v[i-1]) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> vec_n(n);
    for(int i = 0; i < n; i++) cin >> vec_n[i];

    sort(vec_n.begin(), vec_n.end());

    string ans = (check_mapping(vec_n)) ? "YES" : "NO";

    cout << ans;
}
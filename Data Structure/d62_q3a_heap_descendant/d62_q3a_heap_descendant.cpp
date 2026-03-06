#include <bits/stdc++.h>
using namespace std;

set<int> ans;
void recur_find(size_t left, size_t right, size_t n){
    if(left < n){
        ans.insert(left);
        recur_find(left*2 + 1, left*2 + 2, n);
    }

    if(right < n){
        ans.insert(right);
        recur_find(right*2 + 1, right*2 + 2, n);
    }
}

int main(){
    int n, a;
    cin >> n >> a;
    ans.insert(a);
    recur_find(a*2 + 1, a*2 + 2, n);

    cout << ans.size() << endl;
    for(int an : ans){
        cout << an << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v;
    while(n--){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    while(m--){
        int b;
        cin >> b;
        auto itr = upper_bound(v.begin(), v.end(), b);
        itr--;
        if(b < *v.begin()){
            cout << -1 << endl;
        }else if(b >= v.back()){
            cout << v.back() << endl;
        }else{
            cout << *itr << endl;
        }
    }
}
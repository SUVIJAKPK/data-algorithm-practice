#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> v[i][j];
        }
    }

    if(n > 1){
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                v[i][j] = max(v[i][j] + v[i+1][j] , v[i][j] + v[i+1][j+1]);
            }
        }
    }
    cout << v[0][0];
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    int ans = -10000;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            int sum = 0;

            for(int k = 0; i+k < n && j+k < n; k++){
                sum += A[i+k][j+k];
                ans = max(ans, sum);
            }
        }
    }

    cout << ans;
}
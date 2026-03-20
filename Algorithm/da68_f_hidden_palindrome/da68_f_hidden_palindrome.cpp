#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    
    vector<vector<int>> table(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++) table[i][i] = 1;

    for(int len = 1; len < N; len++){
        for(int l = 0; l + len < N; l++){
            int r = l + len;

            if(s[l] == s[r]){
                if(len == 1) table[l][r] = 2;
                else table[l][r] = table[l+1][r-1] + 2;
            }else{
                table[l][r] = max(table[l][r-1], table[l+1][r]);
            }
        }
    }
    cout << table[0][N-1];
    // for(auto t : table){
    //     for(auto p : t){
    //         cout << p << " ";
    //     }
    //     cout << endl;
    // }
}
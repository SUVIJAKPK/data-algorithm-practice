#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b,int top,int bottom,int left,int right){
    if(a == 0){
        v[top][left] = b;
        return;
    }

    int midRow = (top + bottom)/2;
    int midCol = (left + right)/2;

    recur(v, a-1, b, top, midRow, left, midCol);
    recur(v, a-1, b-1, top, midRow, midCol, right);
    recur(v, a-1, b+1, midRow, bottom, left, midCol);
    recur(v, a-1, b,   midRow, bottom, midCol, right);
}

int main(){
    int a,b;
    cin >> a >> b;

    int n = 1 << a;
    vector<vector<int>> H(n, vector<int>(n));

    recur(H, a, b, 0, n, 0, n);
    

    for(auto ii : H){
        for(auto jj : ii){
            cout << jj << " ";
        }
        cout << endl;
    }
}
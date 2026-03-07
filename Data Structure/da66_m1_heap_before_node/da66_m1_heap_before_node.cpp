#include <bits/stdc++.h>
using namespace std;

int n;
set<int> node;

void binary_heap(int m){
    if(m >= n) return;

    int left = 2 * m + 1;
    int right = 2 * m + 2;
    
    node.erase(m);

    binary_heap(left);
    binary_heap(right);
}

int main(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) node.insert(i);

    binary_heap(m);

    cout << node.size() << endl;
    for(auto a : node) cout << a << " ";
}

//             0
//     1               2
// 3       4       5        6       
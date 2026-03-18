#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n;
    int a = 0, b = 1;
    if(n == 0){
        b = 0;
    }else if(n >= 2){
        for(int i = 2; i <= n; i++){
            long long c = a + b;
            a = b;
            b = c;
        }
    }
    cout << b;

}
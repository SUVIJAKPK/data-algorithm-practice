#include <bits/stdc++.h>
using namespace std;

int lawn_Mowing(vector<int> &v, int a, int b, int k, int ans, int n){
    if(a >= v.size()) return ans;
    int sum = ans;
    sum += n*k;
    sum += v[a]; 
    if(sum > b) return ans;
    return lawn_Mowing(v,a+1,b,k,sum,n+1);
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << lawn_Mowing(A,a,b,k,0,0) << endl;
    }
}
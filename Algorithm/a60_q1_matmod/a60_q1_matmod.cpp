#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod;

struct Matrix {
    ll a, b, c, d;
};

Matrix multiply_Matrix(Matrix x, Matrix y){
    Matrix ans;
    
    ans.a = ((x.a * y.a) + (x.b * y.c)) % mod;
    ans.b = ((x.a * y.b) + (x.b * y.d)) % mod;
    ans.c = ((x.c * y.a) + (x.d * y.c)) % mod;
    ans.d = ((x.c * y.b) + (x.d * y.d)) % mod;

    return ans;
}

Matrix power_Matrix(Matrix m, ll n){
    if(n == 1) return m;

    Matrix half = power_Matrix(m, n/2);

    if(n % 2 == 0){
        return multiply_Matrix(half, half);
    }else{
        return multiply_Matrix(m, multiply_Matrix(half, half));
    }
}

int main(){
    ll n;
    cin >> n >> mod;

    Matrix A;
    cin >> A.a >> A.b >> A.c >> A.d;

    Matrix anss = power_Matrix(A, n);
    cout << anss.a % mod<< " " << anss.b % mod << " " << anss.c % mod << " " << anss.d % mod;
}
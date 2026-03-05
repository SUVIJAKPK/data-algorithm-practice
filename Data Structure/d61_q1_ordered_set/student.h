#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<T> seen;
    for(auto a : A){
        v.push_back(a);
        seen.insert(a);
    }

    for(auto b : B){
        if(!seen.count(b)) v.push_back(b);
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set seen(B.begin(), B.end());
    for(auto a:A){
        if(seen.count(a)) v.push_back(a);
    }
    return v;
}

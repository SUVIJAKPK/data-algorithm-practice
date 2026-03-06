#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    map<string,int> vote;
    while(N--){
        string name;
        cin >> name;
        if(!vote.count(name)){
            vote[name] = 1;
        }else{
            vote[name]++;
        }
    }

    vector<int> vec;
    for(auto v : vote){
        vec.push_back(-1 * v.second);
        // cout << v.second << endl;
    }
    sort(vec.begin(), vec.end());

    if(vec.size() > K){
        cout << vec[K-1] * -1;
    }else{
        cout << vec[vec.size() - 1] * -1;
    }
}
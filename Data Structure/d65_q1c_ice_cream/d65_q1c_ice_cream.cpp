#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,start;
    vector<pair<int,int>> day_save;
    vector<long long> acc;
    cin >> n >> m >> start;
    acc.push_back(start);
    long long current_money = start;
    for(int i=0;i<n;i++){
        int a,s;
        cin >> a >> s;
        day_save.push_back(make_pair(a,s));
    }
    sort(day_save.begin(),day_save.end());

    for(auto &p : day_save){
        int a,s;
        a = p.first;
        s = p.second;

        while(acc.size() < a){
            acc.push_back(current_money + acc.back());
        }

        current_money = s;
        acc.push_back(current_money + acc.back());

    }

    for(int i=0;i<m;i++){
        long long p,x;
        cin >> p >> x;
        
        while(acc.size()-1 < x){
            acc.push_back(current_money + acc.back());
        }

        if(acc[x] >= p){
            auto it = lower_bound(acc.begin(),acc.end(),p);
            cout << it - acc.begin() << " ";
        }
        else{
            long long money = 0;
            while(acc.back() < acc[x] + p){
                acc.push_back(current_money + acc.back());
            }

            auto it = lower_bound(acc.begin(),acc.end(),acc[x]+p);
            cout << it - acc.begin() << " ";
        }
    }
}
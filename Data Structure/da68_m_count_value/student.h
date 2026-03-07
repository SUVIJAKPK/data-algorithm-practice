#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <bits/stdc++.h>
// you can also include anything else here

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  if(data.empty()) return std::vector<size_t>();
  std::vector<size_t> r;
  //write your code here
  std::vector<int> vec;
  for(auto dd : data){
    vec.push_back(dd.second);
  }

  sort(vec.begin(), vec.end());

  for(auto q : queries){
    auto lo = lower_bound(vec.begin(), vec.end(), q.first);
    auto up = upper_bound(vec.begin(), vec.end(), q.second);
    r.push_back(up - lo);
  }
  return r;
}

#endif

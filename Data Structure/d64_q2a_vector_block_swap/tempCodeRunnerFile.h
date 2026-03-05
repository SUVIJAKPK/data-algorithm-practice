#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <bits/stdc++.h>
template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if(b - a >= m && m > 0){
    size_t i = 0;
    auto left = a, right = b;
    while(i < m){
      std::swap(*left++, *right++);
      i++;
    }
    return true;
  }
  return false;
}

#endif

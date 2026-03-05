#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  size_t st = a, la = b;
  while(st < la){
    swap(mData[(mFront + st++)%mCap], mData[(mFront + la--)%mCap]);
  }
}

#endif

#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <bits/stdc++.h>
using namespace std;
//you can include any other file here
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  unordered_set<T> seen;
  T *new_vector = new T[mSize];
  size_t newSize = 0;

  for(int i = 0; i < mSize; i++){
    if(seen.insert(mData[i]).second) new_vector[newSize++] = mData[i];
  }

  delete [] mData;
  mData = new_vector;
  mSize = newSize;
  mCap = newSize;
}

#endif

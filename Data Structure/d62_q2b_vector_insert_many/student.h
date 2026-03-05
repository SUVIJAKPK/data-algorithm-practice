#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  std::sort(data.begin(), data.end());
  size_t newSize = mSize + data.size();
  
  T *new_data = new T[newSize];
  
  size_t pos_data = 0, pos_old = 0, pos_newdata = 0;
  
  while(pos_newdata < newSize){
    if(pos_old == data[pos_data].first && pos_data < data.size()){
      new_data[pos_newdata++] = data[pos_data++].second;
    }else{
      new_data[pos_newdata++] = mData[pos_old++];
    }
  }
  
  delete [] mData;
  mData = new_data;
  mSize = newSize;
  mCap = newSize;
}

#endif

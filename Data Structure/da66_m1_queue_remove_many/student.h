#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos){
  if(pos.empty()) return;

  std::vector<bool> check(mSize , false);
  for(auto p : pos){
    check[p] = true;
  }

  size_t new_size = mSize - pos.size();

  if(new_size == 0){
    mSize = 0;
    mFront = 0;
    return;
  }

  size_t i_new = 0;

  for(int i = 0; i < mSize; i++){
    if(!check[i]){
      mData[(mFront + (i_new++)) % mCap] = mData[(mFront + i) % mCap];
    }
  }

  mSize = new_size;
}

#endif

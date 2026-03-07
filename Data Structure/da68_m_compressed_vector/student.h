#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "compressed_vector.h"
#include <cstdlib>

template <typename T> void CP::CompressedVector<T>::expand(size_t capacity) {
  // write your code here
  T* newDataV = new T[capacity]();
  size_t* newDataL = new size_t[capacity]();

  for(size_t i = 0; i < mSize; i++){
    newDataV[i] = mDataV[i];
    newDataL[i] = mDataL[i];
  }

  delete [] mDataV;
  delete [] mDataL;
  mDataV = newDataV;
  mDataL = newDataL;
  mCap = capacity;
}

template <typename T>
void CP::CompressedVector<T>::insert(int index, const T &element) {
  size_t x=0,pos=0;
  while(pos<mSize&&x+mDataL[pos]<=(size_t)index){
    x+=mDataL[pos];
    pos++;
  }
  if(mDataV[pos]==element&&pos<mSize){
    mDataL[pos]++;
    return;
  }
  if(pos>0&&mDataV[pos-1]==element){
    mDataL[pos-1]++;
    return;
  }
  ensureCapacity(mSize+1);
  for(size_t i=mSize;i>pos;i--) {
      mDataV[i]=mDataV[i-1];
      mDataL[i]=mDataL[i-1];
  }

  mDataV[pos] = element;
  mDataL[pos] = 1;
  mSize++;
}

template <typename T> T &CP::CompressedVector<T>::operator[](int index) const {
  // write your code here
  size_t x=0,pos=0;
  while(pos<mSize&&x+mDataL[pos]<=(size_t)index){
    x+=mDataL[pos];
    pos++;
  }
  return mDataV[pos];
}

#endif

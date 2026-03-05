#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  // Your code here
  aux = !aux;
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  return aux ? (mData[(mFront + mSize - 1) % mCap]) : (mData[mFront]);
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  return aux ? (mData[mFront]) : (mData[(mFront + mSize - 1) % mCap]);
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  if(aux){
    mFront = (mFront + mCap - 1) % mCap;
    mData[mFront] = element;
  }else{
    mData[(mFront + mSize) % mCap] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if(!aux) mFront = (mFront + 1) % mCap;
  mSize--;
}

#endif
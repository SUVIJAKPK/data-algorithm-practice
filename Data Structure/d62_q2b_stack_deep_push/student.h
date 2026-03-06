#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  ensureCapacity(mSize + 1);
  size_t position = mSize - pos;
  for(size_t i = mSize; i > position; i--){
    mData[i] = mData[i - 1];
  }
  mData[position] = value;
  mSize++;
}

#endif

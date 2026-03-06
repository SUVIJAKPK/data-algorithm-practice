#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for(auto &ss : ls){
    mHeader->prev->next = ss.mHeader->next;
    ss.mHeader->next->prev = mHeader->prev;

    ss.mHeader->prev->next = mHeader;
    mHeader->prev = ss.mHeader->prev;
    mSize += ss.mSize;

    ss.mHeader->next = ss.mHeader;
    ss.mHeader->prev = ss.mHeader;
    ss.mSize = 0;
  }

}

#endif

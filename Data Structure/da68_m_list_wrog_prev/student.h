#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
size_t CP::list<T>::fix_wrong() {
  node* cur = mHeader->next;
  if(cur == mHeader) return 0;

  size_t ans = 0;
  if(cur->prev != mHeader){
    cur->prev = mHeader;
    ans++;
  }

  while(cur != mHeader){
    if(cur->next->prev != cur){
      cur->next->prev = cur;
      ans++;
    }
    cur = cur->next;
  }

  return ans;
}

#endif
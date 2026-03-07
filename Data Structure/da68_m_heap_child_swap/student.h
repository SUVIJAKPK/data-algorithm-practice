#include "priority_queue.h"
#include <utility>

template <typename T,typename Comp>
void CP::priority_queue<T, Comp>::child_swap(size_t k) {
  if(k >= mSize) return;

  size_t p = k;
  size_t n = 1;
  while(true){
    size_t odd = (p*2) + 1;
    if(odd >= mSize) break;
    
    for(size_t i = 0; i < n; i++){
      T m_odd = mData[odd + i]; 
      mData[odd + i] = mData[odd + i + n];
      mData[odd + i + n] = m_odd;
    }

    p = odd;
    n *= 2;
  }

}

//                   0
//         1                   2
//     3        4          5       6
//   7   8    9   10     11  12  13  14
// 15 161718 1920 21 22 23
// 1
// 2
// 4
// 8
#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    auto value = mData[(mFront + pos) % mCap];
    for(size_t i = pos; i > 0; i--){
        // std::cout << mData[(mFront + i) % mCap];
        mData[(mFront + i) % mCap] = mData[(mFront + i - 1) % mCap];
    }
    mData[(mFront) % mCap] = value;
}

#endif

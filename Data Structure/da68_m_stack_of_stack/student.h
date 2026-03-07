#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <bits/stdc++.h>

// can include other libs or write util funtion here

template <typename T>
void CP::stack<T>::push(const T& value) {
    //write your code here
    if(mSize == 0 || mData[mSize - 1].size() == mSize){
        mData.push_back(std::vector<T>());
        mSize++;
    }
    mData[mSize - 1].push_back(value);
}

template <typename T>
void CP::stack<T>::pop() {
    if (size() == 0) throw std::out_of_range("index of out range") ;
	//write your code here
    mData[mSize - 1].pop_back();
    if(mData[mSize - 1].empty()){
        mData.pop_back();
        mSize--;
    }
}

template <typename T>
size_t CP::stack<T>::size() const {
    //write your code here
    if(mSize == 0) return 0;
    return (mSize * (mSize - 1))/2 + mData[mSize - 1].size();
}

template <typename T>
const T&  CP::stack<T>::top() const {
    //write your code here
    if (size() == 0) throw std::out_of_range("index of out range") ;
    return mData[mSize - 1].back();
}

/*
Push and pop with steady hand,
or tears may fall from teacher’s stand.
*/

#endif
#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    T *newarr = new T[mSize];
    for(auto i = 0; i < mSize; i++){
        newarr[i] = mData[i];
    }
    delete[] mData;
    mData = newarr;
    mCap = mSize;
}

#endif

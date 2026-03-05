#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here 
  size_t pos = position - begin();
  size_t k = last - first;
  expand(mSize + k);

  for(size_t i = mSize; i > pos; --i){
    // std::cout << mData[i] << std::endl;
    mData[i + k - 1] = mData[i - 1];
  }

  for(auto itr = first; itr < last; itr++){
    mData[pos++] = *itr;
    // std::cout << *itr << std::endl;
  }
  mSize += (last - first);
}

#endif

#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  if(pos.empty()) return;
  //write your code here
  int itr_pos = 0, itr_this = 0;
  for(int i = 0; i < mSize; i++){
    if(i == pos[itr_pos] && itr_pos < pos.size()){
      itr_pos++;
    } else {
      mData[itr_this++] = mData[i];
    }
  }
  mSize = itr_this;
}

#endif

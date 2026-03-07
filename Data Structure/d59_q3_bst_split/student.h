#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;

  node* tmp = mRoot;

  node* leftRoot = NULL;
  node* rightRoot = NULL;

  node* leftTail = NULL;
  node* rightTail = NULL;

  while(tmp != NULL){
    if(mLess(tmp->data.first, val)){ // ขวา
      node* next = tmp->right;

      tmp->right = NULL;
      tmp->parent = NULL;

      if(leftRoot == NULL){
        leftRoot = tmp;
      }else{
        leftTail->right = tmp;
        tmp->parent = leftTail;
      }

      leftTail = tmp;
      tmp = next;
    }else{
      node* next = tmp->left;

      tmp->left = NULL;
      tmp->parent = NULL;

      if(rightRoot == NULL){
        rightRoot = tmp;
      }else{
        rightTail->left = tmp;
        tmp->parent = rightTail;
      }

      rightTail = tmp;
      tmp = next;
    }
  }

  mRoot = leftRoot;
  result.mRoot = rightRoot;

  return result;
}

#endif

void replace(const T& x, list<T>& y) {
  //write your code here
  if(y.mSize > 0){
    node* dec = mHeader->next;
    while(dec != mHeader){
      if(dec->data == x){
        node* nc = dec->next;
        list<T> tmp(y);
        dec->prev->next = tmp.mHeader->next;
        tmp.mHeader->next->prev = dec->prev;
        nc->prev = tmp.mHeader->prev;
        tmp.mHeader->prev->next = nc;

        mSize += y.mSize - 1;
  
        tmp.mHeader->next = tmp.mHeader;
        tmp.mHeader->prev = tmp.mHeader;
        tmp.mSize = 0;

        delete dec;
        dec = nc;
      }else{
        dec = dec->next;
      }
    }
  }else{
    node* dec = mHeader->next;
    while(dec != mHeader){
      if(dec->data == x){
        node* nc = dec->next;
        dec->prev->next = nc;
        nc->prev = dec->prev;
  
        delete dec;
        mSize--;
        dec = nc;
      }else{
        dec = dec->next;
      }
    }
  }
}

#ifndef __STUDENT_H_
#define __STUDENT_H_

void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if(mSize <= 0) return;
    size_t size1 = (mSize + 1) / 2;
    size_t size2 = mSize - size1;

    node* dec = mHeader->next;
    size_t k = 0;
    while(dec != mHeader && k < size1){
        dec = dec->next;
        k++;
    }
    node* dec1 = dec->prev;
    node* dec2 = dec;

    //list1
    if(size1 > 0){
        list1.mHeader->prev->next = mHeader->next;
        mHeader->next->prev = list1.mHeader->prev;
        dec1->next = list1.mHeader;
        list1.mHeader->prev = dec1;
        list1.mSize += size1;
    }

    //list2
    if(size2 > 0){
        list2.mHeader->prev->next = dec2;
        dec2->prev = list2.mHeader->prev;
        mHeader->prev->next = list2.mHeader;
        list2.mHeader->prev = mHeader->prev;
        list2.mSize += size2;
    }

    //reset
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;
}

#endif
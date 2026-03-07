#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "list.h"
#include <bits/stdc++.h>

template <typename T>
void CP::list<T>::zigzag(CP::list<T> &ls) {

    if(ls.mSize == 0) return;
    if(mSize == 0){
        std::swap(mHeader,ls.mHeader);
        std::swap(mSize,ls.mSize);
        return;
    }

    node* node_list1 = mHeader->next; 
    node* node_list2 = ls.mHeader->next;

    // 1  2  3  4
    //   x  y  z  a
    if(mSize == ls.mSize){
        int i = 0;
        while(i < mSize - 1){
            node* next_l1 = node_list1->next;
            node* next_l2 = node_list2->next;

            node_list2->next = node_list1->next; // x -> 2
            node_list1->next->prev = node_list2; // 2 -> x
            node_list1->next = node_list2; // 1 -> x
            node_list2->prev = node_list1; // x -> 1

            node_list1 = next_l1;
            node_list2 = next_l2;
            i++;
        }
        node_list1->next = node_list2;
        node_list2->prev = node_list1;
        node_list2->next = mHeader;
        mHeader->prev = node_list2;
        mSize += ls.mSize;

        ls.mHeader->next = ls.mHeader;
        ls.mHeader->prev = ls.mHeader;
        ls.mSize = 0;
        return;
    }
    
    // 1  2  3  4
    //   x  y  z  a  b  c
    if(mSize < ls.mSize){
        int i = 0;
        while(i < mSize - 1){
            node* next_l1 = node_list1->next;
            node* next_l2 = node_list2->next;

            node_list2->next = node_list1->next; // x -> 2
            node_list1->next->prev = node_list2; // 2 -> x
            node_list1->next = node_list2; // 1 -> x
            node_list2->prev = node_list1; // x -> 1

            node_list1 = next_l1;
            node_list2 = next_l2;
            i++;
        }
        node_list1->next = node_list2;
        node_list2->prev = node_list1;
        ls.mHeader->prev->next = mHeader;
        mHeader->prev = ls.mHeader->prev;
        mSize += ls.mSize;
        
        ls.mHeader->next = ls.mHeader;
        ls.mHeader->prev = ls.mHeader;
        ls.mSize = 0;
        return;
    }
    
    // 1  2  3  4  5  6
    //   x  y  z
    if(mSize > ls.mSize){
        int i = 0;
        while(i < ls.mSize){
            node* next_l1 = node_list1->next;
            node* next_l2 = node_list2->next;

            node_list2->next = node_list1->next; // x -> 2
            node_list1->next->prev = node_list2; // 2 -> x
            node_list1->next = node_list2; // 1 -> x
            node_list2->prev = node_list1; // x -> 1

            node_list1 = next_l1;
            node_list2 = next_l2;
            i++;
        }
        mSize += ls.mSize;
        
        ls.mHeader->next = ls.mHeader;
        ls.mHeader->prev = ls.mHeader;
        ls.mSize = 0;
        return;
    }
}


#endif

#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b){
    stack<T> newStack;
    for(int i = 0; i <= b; i++){
        newStack.push(top());
        if(i >= a){
            newStack.push(top());
        }
        pop();
    }
    while(!newStack.empty()){
        push(newStack.top());
        newStack.pop();
    }
}

#endif
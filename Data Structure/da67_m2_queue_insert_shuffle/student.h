#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"

template <typename T>
void CP::queue<T>::insert_shuffle(std::vector<T> items, size_t pos)
{
	// write your code here
	queue<T> newQ;
	newQ.expand(mSize + items.size());
	
	size_t count = 0;
	while(count < pos){
		newQ.push(front());
		pop();
		count++;
	}

	size_t inn = 0;
	for(size_t i = 0; i < items.size(); i++){
		newQ.push(items[i]);
		if(mSize){
			newQ.push(front());
			pop();
		}
	}

	while(mSize){
		newQ.push(front());
		pop();
	}

	*this = newQ;
}

#endif

#pragma once
#ifndef STACK_DEF_H
#define STACK_DEF_H

#include "Stack.h"
using namespace Stack;

template <typename T>
void stack<T>::push(const T DATA) {
	if (topIndex == CAPACITY) {
		std::cerr << "Cannot push to stack. Capacity reached." << std::endl;
		return;
	}

	container[topIndex] = DATA;
	top = &container[topIndex];
	topIndex++;
}

#endif // !STACK_DEF_H

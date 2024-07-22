#pragma once
#ifndef STACK_DEF_H
#define STACK_DEF_H

#include "Stack.h"
using namespace Stack;

// Push operation
template <typename T>
void stack<T>::push(const T DATA) 
{
	if (topIndex == CAPACITY) 
	{
		std::cerr << "Cannot push to stack. Capacity reached." << std::endl;
		return;
	}

	container[topIndex] = DATA;
	top = &container[topIndex];
	topIndex++;
}

// Pop operation
template <typename T>
void stack<T>::pop() 
{
	if (top == nullptr)
	{
		std::cerr << "Cannot pop on an empty stack." << std::endl;
		return;
	}

	container[topIndex - 1] = T();
	topIndex = ((topIndex == 0) ? 0 : --topIndex);
	top = ((topIndex == 0) ? nullptr : &container[topIndex - 1]);
}

#endif // !STACK_DEF_H

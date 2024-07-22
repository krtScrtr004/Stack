#pragma once
#ifndef STACK_DEF_H
#define STACK_DEF_H

#include "Stack.h"
using namespace Stack;

// Push operation
template <typename T>
void stack<T>::push(const T DATA) 
{
	if (TopIndex == CAPACITY)
	{
		std::cerr << "Cannot push to stack. Capacity reached." << std::endl;
		return;
	}

	TopIndex++;
	container[TopIndex] = DATA;
	Top = &container[TopIndex];
}

// Pop operation
template <typename T>
void stack<T>::pop() 
{
	if (Top == nullptr)
	{
		std::cerr << "Cannot pop on an empty stack." << std::endl;
		return;
	}

	container[TopIndex] = T();
	TopIndex--;
	Top = ((TopIndex < 0) ? nullptr : &container[TopIndex]);
}

template <typename T>
T stack<T>::top()
{
	return ((Top != nullptr && TopIndex >= 0) ? *Top : T());
}

#endif // !STACK_DEF_H

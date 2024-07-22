#pragma once
#ifndef STACK_H 
#define STACK_H

#include <array>
#include <iostream>
#include <ostream>

#define CAPACITY 10000

namespace Stack
{
	template <typename Type>
	class stack
	{
	private:
		int TopIndex;
		Type* Top;

		std::array<Type, CAPACITY> container;

	public:
		stack() : container(), TopIndex(-1), Top(nullptr) {}

		void push(const Type);
		void pop();
		Type top();
	};

#include "StackDef.h"
}

#endif // !STACK_H 

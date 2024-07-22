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
		friend std::ostream& operator<<(std::ostream& os, const stack<Type>& STACK) {
			if (STACK.top != nullptr) {
				os << *(STACK.top);
			}

			return os;
		}

	private:
		std::size_t topIndex;
		Type* top;

		std::array<Type, CAPACITY> container;

	public:
		stack() : topIndex(0), top(nullptr) {}

		void push(const Type);
	};

#include "StackDef.h"
}

#endif // !STACK_H 

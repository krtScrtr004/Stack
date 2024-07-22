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

		std::array<Type, CAPACITY> container;

	public:
		stack() : container(), TopIndex(-1) {}

		void push(const Type)
		{
			if (TopIndex == CAPACITY)
			{
				std::cerr << "Cannot push to stack. Capacity reached." << std::endl;
				return;
			}

			TopIndex++;
			container[TopIndex] = DATA;
		}

		void pop()
		{
			if (TopIndex < 0)
			{
				std::cerr << "Cannot pop on an empty stack." << std::endl;
				return;
			}

			container[TopIndex] = T();
			TopIndex--;
		}

		Type top() { return ((Top != nullptr && TopIndex >= 0) ? *Top : T()); }
	};
}

#endif // !STACK_H 

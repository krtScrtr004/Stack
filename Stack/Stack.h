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
		std::array<Type, CAPACITY> container;
		int TopIndex;

	public:
		stack() : container(), TopIndex(-1) {}

		void push(const Type DATA)
		{
			if (isFull())
			{
				std::cerr << "Cannot push to stack. Capacity reached." << std::endl;
				return;
			}

			TopIndex++;
			container[TopIndex] = DATA;
		}

		void pop()
		{
			if (isEmpty())
			{
				std::cerr << "Cannot pop on an empty stack." << std::endl;
				return;
			}

			container[TopIndex] = Type();
			TopIndex--;
		}

		Type top() const { return (!isEmpty() ? container[TopIndex] : Type()); }

		inline bool isFull() const { return TopIndex == CAPACITY; }

		inline bool isEmpty() const { return TopIndex < 0; }
	};
}

#endif // !STACK_H 

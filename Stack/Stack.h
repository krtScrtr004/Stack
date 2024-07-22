#pragma once
#ifndef STACK_H 
#define STACK_H

#include <array>
#include <iostream>
#include <list>
#include <ostream>

#define CAPACITY 10000

namespace Stack
{
    template <typename Type>
    class stack
    {
    protected:
        virtual void push(const Type& data) = 0;
        virtual void pop() = 0;
        virtual Type top() const = 0;
        virtual inline bool isFull() const = 0;
        virtual inline bool isEmpty() const = 0;

    public:
        virtual ~stack() = default; // Add virtual destructor for proper cleanup
    };

    template <typename Type>
    class stackArray : public stack<Type>
    {
    private:
        std::array<Type, CAPACITY> container;
        int TopIndex;

    public:
        stackArray() : TopIndex(-1) {}

        void push(const Type& data) override
        {
            if (isFull())
            {
                std::cerr << "Stack overflow." << std::endl;
                return;
            }

            container[++TopIndex] = data;
        }

        void pop() override
        {
            if (isEmpty())
            {
                std::cerr << "Stack underflow." << std::endl;
                return;
            }

            container[TopIndex--] = Type();
        }

        Type top() const override { return (!isEmpty() ? container[TopIndex] : Type()); }

        inline bool isFull() const override { return TopIndex == CAPACITY - 1; }

        inline bool isEmpty() const override { return TopIndex < 0; }
    };

    template <typename Type>
    class stackList : public stack<Type>
    {
    private:
        std::list<Type> container;

    public:
        stackList() {}

        void push(const Type& data) override
        {
            if (isFull())
            {
                std::cerr << "Stack overflow" << std::endl;
                return;
            }

            container.push_back(data);
        }

        inline bool isFull() const override { return (container.size() == CAPACITY); }

        inline bool isEmpty() const override { return (container.size() < 1); }
    };
}

#endif // STACK_H

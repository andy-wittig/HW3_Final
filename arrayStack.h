#ifndef ARRAY_STACK
#define ARRAY_STACK

#include "stack.h"

template<class ItemType>
class ArrayStack: public StackInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 100;
    ItemType items[DEFAULT_CAPACITY];
    int top;
public:
    ArrayStack() {
        top = -1;
    }

    bool isEmpty() const {
        return top < 0;
    }

    bool push(const ItemType& newEntry) {
        bool canPush = top < DEFAULT_CAPACITY - 1;

        if (canPush) {
            top++;
            items[top] = newEntry;
        }
        return canPush;
    }

    bool pop() {
        bool canPop = !isEmpty();

        if (canPop) {
            top--;
        }

        return canPop;
    }

    ItemType peek() const {
        bool canPeek = !isEmpty();

        if (canPeek) {
            return items[top];
        }
        else {
            throw "empty stack";
        }
    }

    ~ArrayStack() {}
};
#endif
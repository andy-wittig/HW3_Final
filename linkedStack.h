#pragma once
#ifndef LINKED_STACK
#define LINKED_STACK

#include "stack.h"
#include "node.h"

template <class ItemType>
class linkedStack : public StackInterface<ItemType>
{
private:
    Node<ItemType>* topPtr; //head pointers are for lists, top is used for stacks
public:
    linkedStack() : topPtr(nullptr) {}

    bool isEmpty() const //returns if stack is empty
    {
        return (topPtr == nullptr);
    }

    bool push(const ItemType& newEntry) //adds new node to front, reduces time complexity since topPtr is already the top of stack
    {
        bool emptyStack = isEmpty();
        if (!emptyStack)
        {
            Node<ItemType>* newPtr = new Node<ItemType>(newEntry);
            newPtr->setNext(topPtr);
            topPtr = newPtr;
        }
        else
        { 
            topPtr = new Node<ItemType>(newEntry, nullptr);
        }
        return true;
    }

    bool pop() //deletes top node
    {
        bool canPop = !isEmpty();
        if (canPop)
        {
            Node<ItemType>* ptrToDelete = topPtr;
            if (topPtr->getNext() != nullptr)
            {
                topPtr = topPtr->getNext();
                free(ptrToDelete);
                return true;
            }
            else
            { 
                topPtr = nullptr; 
            }
            
        }
        else { return false; }
    }

    ItemType peek() const //returns top node item
    {
        bool canPeek = !isEmpty();
        if (canPeek)
        {
            return topPtr->getItem();
        }
    }

    ~linkedStack() {};
};

#endif


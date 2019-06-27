#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H

#include <iostream>
#include <string>
#include <cassert>

#include "stackADT.h"

using namespace std;

//Definition of the node;
struct nodeSinger{
    string song;
    string singer;
    string album;
    int year;
    nodeSinger *link;
};

template <class Type>
class linkedStackType: public stackADT<Type>
{
    public:
        //Default constructor.
        linkedStackType();

        //Copy constructor.
        linkedStackType(const linkedStackType<Type>& otherStack);

        //Overload the assignment operator.
        const linkedStackType<Type>& operator = (const linkedStackType<Type>&);

        //Checks if stack is empty.
        bool isEmptyStack() const;

        //Checks if stack is full.
        bool isFullStack() const;

        //Initialize an empty stack.
        void initializeStack();

        //Adds new item to the stack.
        void push(const Type& newItem);

        //Push multiple items to the stack
        void pushMulti(string data);

        //returns the top item in the stack.
        Type top() const;

        //Remove the top item in the stack.
        void pop();


        //Creates a nodeSinger.
        Type* createNodeSinger();


        //Deconstructor
        ~linkedStackType();

    private:

        //Pointer that points to the top of the stack.
        nodeSinger *stackTop;
        void copyStack(const linkedStackType<Type>& otherStack);
};

#endif // LINKEDSTACKTYPE_H

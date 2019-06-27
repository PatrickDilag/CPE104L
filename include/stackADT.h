#ifndef STACKADT_H
#define STACKADT_H

template <class Type>
class stackADT
{
    public:
        //Initialize an emtpy stack.
        virtual void initializeStack() = 0;

        //Checks if stack is empty.
        virtual bool isEmptyStack() const = 0;

        //Checks if stack is full.
        virtual bool isFullStack() const = 0;

        //Add new item to stack.
        virtual void push(const Type& newItem) = 0;

        //Return the top item in the stack.
        virtual Type top() const = 0;

        //Delete the top item in the stack.
        virtual void pop() = 0;
};

#endif // STACKADT_H

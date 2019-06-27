#include <iostream>
#include <fstream>
#include <string>

#include "linkedStackType.h"
#include "stackADT.h"
#include "fileHandling.h"

using namespace std;

//Default constructor.
template <class Type>
linkedStackType<Type>::linkedStackType(){
    stackTop = nullptr;
}

//Copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack){
    stackTop = nullptr;
    copyStack(otherStack);
}

//Checks if stack is empty.
template <class Type>
bool linkedStackType<Type>::isEmptyStack() const{
    return (stackTop == nullptr);
}

//Checks if stack is full.
template <class Type>
bool linkedStackType<Type>::isFullStack() const{
    return false;
}

//itialize an empty stack.
template <class Type>
void linkedStackType<Type>::initializeStack(){
    nodeSinger *temp;

    while(stackTop != nullptr){
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
}

//Creates a nodeSinger.
template <class Type>
Type* linkedStackType<Type>::createNodeSinger(){
    Type* ptr = new Type;

    return ptr;
}

//Adds new item to the stack.
template <class Type>
void linkedStackType<Type>::push(const Type& newItem){
    nodeSinger *newNode;

    newNode = new nodeSinger;

    newNode->singer = newItem.singer;
    newNode->song = newItem.song;
    newNode->year = newItem.year;
    newNode->album = newItem.album;
    newNode->link = stackTop;
    stackTop = newNode;
}

template <class Type>
void linkedStackType<Type>::pushMulti(string data){
    ifstream ifs;
    char x[50];
    Type* ptr;

    ifs.open(data);

    if(!ifs.eof()){
        while(!ifs.eof()){
            ptr = new Type;

            ifs.getline(x, 50, ';');
            ptr->singer = x;
            ifs.getline(x, 50, ';');
            ptr->song = x;
            ifs.getline(x, 50, ';');
            ptr->album = x;
            ifs.getline(x, 50);
            ptr->year = atoi(x);

            push(*ptr);
        }
    }else{
        cout << "Error in file handling." << endl;
    }


}

//returns the top item in the stack.
template<class Type>
Type linkedStackType<Type>::top() const{
    assert(stackTop != nullptr);
    return *stackTop;
}

//Remove the top item in the stack.
template <class Type>
void linkedStackType<Type>::pop(){
    nodeSinger *temp;

    if(stackTop != nullptr){
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }else{
        cout << "Cannot remove from an empty stack." << endl;
    }
}

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack){
    nodeSinger *newNode, *current, *last;

    if(stackTop != nullptr){
        initializeStack();
    }

    if(otherStack.stackTop == nullptr){
        stackTop = nullptr;
    }else{
        current = otherStack.stackTop;
        stackTop = new nodeSinger;

        stackTop->album = current->album;
        stackTop->singer = current->singer;
        stackTop->song = current->song;
        stackTop->year = current->year;
        stackTop->link = nullptr;

        last = stackTop;
        current = current->link;

        while(current != nullptr){
            newNode = new nodeSinger;

            newNode->album = current->album;
            newNode->singer = current->singer;
            newNode->song = current->song;
            newNode->year = current->year;
            newNode->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

//Deconstructor
template <class Type>
linkedStackType<Type>::~linkedStackType(){
    initializeStack();
}

//overloading the assignment operator
template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack){
    if(this != &otherStack){    //avoid self-copy
        copyStack(otherStack);
    }

    return *this;
}




template class linkedStackType<nodeSinger>;

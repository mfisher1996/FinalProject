#ifndef MYSTACK_H
#define MYSTACK_H


#include <iostream>
#include <cassert>
using namespace std;

template <class Type>
class myStack
{
    public:
        myStack(int x = 100);
        myStack(const myStack<Type>& otherStack);
        const myStack<Type>& operator=(const myStack<Type>&);
        void initializeStack();
        bool isEmptyStack() const;
        bool isFullStack() const;
        void push(Type item);
        void pop();
        Type top() const;
        ~myStack();

    private:

        void copyStack(const myStack<Type>& otherStack);

        int maxStackSize;
        int stackTop;
        Type *list;
};

template <class Type>
myStack<Type>::myStack(int x)
{
    if(x <= 0)
    {
        cout<< "\tThe size of the array to hold the stack must be positive." << endl;
        cout<< "\tCreating an array of size 100..." << endl;

        maxStackSize = 100;
        list = new Type[maxStackSize];
    }
    else
    {
        maxStackSize = x;
        list = new Type[maxStackSize];
    }

    stackTop = 0;

}

template <class Type>
void myStack<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
bool myStack<Type>::isEmptyStack() const
{
    if(stackTop == 0)
    {
        return true;
    }

    return false;
}


template <class Type>
bool myStack<Type>::isFullStack() const
{
    if(stackTop == maxStackSize)
    {
        return true;
    }

    return false;
}

template <class Type>
void myStack<Type>::push(Type info)
{
    list[stackTop] = info;
    stackTop++;
}

template <class Type>
void myStack<Type>::pop()
{
    if(isEmptyStack() == false)
    {
        stackTop--;
    }
    else
    {
        cerr<< "\tThe Stack Is Already Empty. Cannot Pop An Item Out..." << endl;
    }
}

template <class Type>
Type myStack<Type>::top() const
{
    if(stackTop == 0)
    {
        cout<< "\tERROR: Cannot There Are No Items In The Stack!" << endl;
        cout<< "\tTerminating Program..." << endl << endl;
        assert(0 != 0);
    }
    return list[stackTop - 1];
}

template <class Type>
void myStack<Type>::copyStack(const myStack<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new Type[maxStackSize];

    //Perform the copy
    for(int i = 0; i < maxStackSize; i++)
    {
        list[i] = otherStack.list[i];
    }
}

template <class Type>
myStack<Type>::myStack(const myStack<Type>& otherStack)
{
    list = 0;

    copyStack(otherStack);
}

template <class Type>
const myStack<Type>& myStack<Type>::operator=(const myStack<Type>& otherStack)
{
    if(this != &otherStack)
    {
        copyStack(otherStack);
    }

    return *this;
}


template <class Type>
myStack<Type>::~myStack()
{
    delete [] list;
}

#endif // MYSTACK_H

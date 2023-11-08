/*Samuel Wait (s_w188)
 Assignment 1*/
#include <iostream>
#include "mystack.h"

using namespace std;

/*
 * Constructor
 * Usage: MyStack(val);
 * -------------------------
 * A new stack is created and initialized. The initialized stack is made empty.
 * The parameter 'size' is used to determine the maximum number of integer 
 * elements that can be held in the stack.
 */

MyStack::MyStack(int size) {
    max_size = size-1;
    top = -1;
    elements = new int[max_size];
}


/* Destructor
 * -----------------------
 * Release the memory allocated for the stack.
 */

MyStack::~MyStack() {
    delete [] elements;
}

/*
 * Functions: Push, Pop
 * Usage: st.Push(val); val = st.Pop();
 * --------------------------------------------
 * These are the fundamental stack operations that add an element to
 * the top of the stack and remove an element from the top of the stack.
 * A call to pop from an empty stack or to push on a full stack is an error.
 * Make use of IsEmpty()/IsFull() (see below) to avoid the error.
 */

void MyStack::Push(int elem) {
    assert(!IsFull());
    top++;
    elements[top] = elem;
    
}

int MyStack::Pop() {
    assert(!IsEmpty());
    int num = elements[top];
    top--;
    return num;
}

/*
 * Functions: IsEmpty, IsFull
 * Usage: if (!IsEmpty()) ...
 * -----------------------------------
 * Return true if the stack is empty (IsEmpty) or full (IsFull).
 */

bool MyStack::IsEmpty() const{
    return top == -1;
}

bool MyStack::IsFull() const{
    return top == max_size;
}


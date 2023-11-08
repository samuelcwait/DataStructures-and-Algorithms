/*Samuel Wait (s_w188)
 Assignment 1*/
#ifndef _MYSTACK_H_
#define _MYSTACK_H_

class MyStack {
public:
    MyStack(int size);
    ~MyStack();
    void Push(int elem);
    int Pop();
    bool IsEmpty() const;
    bool IsFull() const;

private:
    int *elements; /* To declare a dynamically allocated array of integer elements for a stack (using C++ keyword new) */
    int top;  /* Index of the top element of the stack */
    int max_size;  /* Max number of elements that could be in the stack */
};

#endif

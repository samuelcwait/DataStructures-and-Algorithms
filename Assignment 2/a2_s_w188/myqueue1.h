#ifndef _MYQUEUE1_H_
#define _MYQUEUE1_H_

using namespace std;

class MyQueue{
public:
   MyQueue(int size);
   ~MyQueue();
   void EnQueue(int elem);
   int DeQueue();
   bool IsEmpty() const;
   bool IsFull() const;

private:
    int *elements;    //To declare a dynamically allocated array of integer elements for a queue (using C++ keyword new)
   int rear, front;  //The front and rear indexes of the queue
   int arr_size;     //The length of an array that implements a queue
   int counter;      //The counter variable to keep track of the elements in the queue
};

MyQueue::MyQueue(int size) {
    arr_size = size;
    front = 0;
    rear = -1;
    elements = new int[arr_size];
    counter = 0;
}


MyQueue::~MyQueue() {
    delete [] elements;
}

void MyQueue::EnQueue(int elem) {
    assert(!IsFull());
    rear = (rear+1) % arr_size;
    elements[rear] = elem;
    counter++;
}

int MyQueue::DeQueue() {
    assert(!IsEmpty());
    int result = elements[front];
    front = (front+1) % arr_size;
    counter--;
    return result;
}

bool MyQueue::IsEmpty() const {return counter == 0;}

bool MyQueue::IsFull() const {return counter == arr_size;}

#endif


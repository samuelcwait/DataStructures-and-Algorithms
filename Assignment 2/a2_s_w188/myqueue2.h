#ifndef _MYQUEUE2_H_
#define _MYQUEUE2_H_

using namespace std;

class MyQueue {
public:
   MyQueue(int size);
   ~MyQueue();
   void EnQueue(int elem);
   int DeQueue();
   int CurrentSize();
   bool IsEmpty();
   bool IsFull();

private:
   int *elements;   /* To declare a dynamically allocated array of integer elements for a queue (using C++ keyword new) */
   int front, rear; /* The front and rear indexes of the queue */
   int arr_size;    /* The length of an array that implements a queue */
                    /* Keep in mind that the queue will only hold up to (arr_size - 1) elements */
                    /* In other words, arr_size should be the maximum capacity of the queue plus one */ 
};

MyQueue::MyQueue(int size) {
    arr_size = size;
    front = arr_size-1;
    rear = arr_size-1;
    elements = new int[arr_size+1];
}


MyQueue::~MyQueue() {
    delete [] elements;
}

void MyQueue::EnQueue(int elem) {
    assert(!IsFull());
    rear = rear+1;
    elements[rear] = elem;
}

int MyQueue::DeQueue() {
    assert(!IsEmpty());
    front = front+1;
    int result = elements[front];
    return result;
}

int MyQueue::CurrentSize() {;
    if (front < rear){
        return rear - front;
    }
    if (front > rear){
        return front - rear;
    }
    return 0;
}

bool MyQueue::IsEmpty() {return CurrentSize() == 0;}
bool MyQueue::IsFull() {return CurrentSize() == arr_size;}

#endif

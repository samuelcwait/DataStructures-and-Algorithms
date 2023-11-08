#include <iostream>
#include "myqueue1.h"
// Include one of your queue header files to use its corresponding queue implementation

using namespace std;

int CountStudent(int mouse_stack[], int stack_size, int student_queue[], int queue_size){
    int num_students = queue_size;
    MyQueue students(queue_size);
    for(int i = 0;i < queue_size; i++){
        students.EnQueue(student_queue[i]);
    }
    for(int i = 0; i < queue_size; i++){
        int count = 0;
        int val = students.DeQueue();
        if(val == mouse_stack[i]){
            num_students--;
        }
        if(val != mouse_stack[i]){
            for(int j = 0; j < queue_size-(i+1); j++){
                students.EnQueue(val);
                val = students.DeQueue();
                if(val == mouse_stack[i]){
                    num_students--;
                    break;
                }
                count++;
            }
        }
        if(count == queue_size-(i+1)){
            break;
        }
    }
    return num_students;
}


void Testing(int mice[], int mouse_size, int students[], int student_size) {
   cout << "Testing the CountStudent function..." << endl; 
   cout << "Student Queue: "; 
   for (int i = 0; i < student_size; i++){
     cout << students[i] << " "; 
   }
   cout << endl; 
   cout << "G-Mouse Stack: "; 
   for (int i = 0; i < mouse_size; i++){
     cout << mice[i] << " "; 
   }
   cout << endl; 
   cout << "Number of students who are unable to have the gaming mice is: " << CountStudent(mice, mouse_size, students, student_size) << endl; 
}

int main() {
   
   //Test case 1
   const int t1_student_size = 4;
   int t1_students[t1_student_size] = {1,1,0,0};
   const int t1_mouse_size = 4;
   int t1_mice[t1_mouse_size] = {0,1,0,1};
   Testing(t1_mice, t1_mouse_size, t1_students, t1_student_size);

   //Test case 2
   const int t2_student_size = 6;
   int t2_students[t2_student_size] = {1,1,1,0,0,1};
   const int t2_mouse_size = 6;
   int t2_mice[t2_mouse_size] = {1,0,0,0,1,1};
   Testing(t2_mice, t2_mouse_size, t2_students, t2_student_size);

   //Test case 3
   const int t3_student_size = 7;
   int t3_students[t3_student_size] = {1,1,0,0,1,1,0};
   const int t3_mouse_size = 7;
   int t3_mice[t3_mouse_size] = {0,1,0,1,0,0,0};
   Testing(t3_mice, t3_mouse_size, t3_students, t3_student_size);
      
   return 0;
}

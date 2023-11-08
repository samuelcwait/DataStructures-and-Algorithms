#include <iostream>

using namespace std;

// This function exchanges the values of var1 and var2.
void Swap(int& var1, int& var2){
    int temp = var1;
    var1 = var2;
    var2 = temp;
}
// This function performs the 'percolate down' operation from node arr[index].
void PercolateDown(int arr[], int index, int size) {
    int leftchild_index = 2*index;
    //initializes the index of the left child to 2*parent index
    int rightchild_index = 2*index+1;
    //initializes the index of the right child to 2*parent index + 1
    int min_index = index;
    //initializes the min index to the parent index
    if(rightchild_index < size && arr[rightchild_index] < arr[min_index]){
    //sets min index to right child index if right child index
        //is smaller than size and min index so far
        min_index = rightchild_index;
    }
    if(leftchild_index < size && arr[leftchild_index] < arr[min_index]){
    //sets the min index to left child index if left child index
        //is smaller than size and min index so far
        min_index = leftchild_index;
    }
    if(min_index != index){
    //if min index is no longer the parent index
    //then swap the parent and min index and recursively call the function
        //with the min index as the new parent index
        Swap(arr[index], arr[min_index]);
        PercolateDown(arr, min_index, size);
    }
}

// This function swaps the minimum-value element with the last element 
// in arr[first..last] and leaves (does not delete) the minimum-value element.
// After DeleteMin, the heap shrinks by 1.
void DeleteMin(int arr[], int& last) {
    Swap(arr[1], arr[last]);//swaps the root node at index 1 with the last node
    PercolateDown(arr, 1, last);
    //calls percolatedown to maintain minheap property
}

// This functions coverts the array arr[] to a heap, i.e., it has the *head-order* 
// property while it is interpreted as a complete binary tree.
void BuildHeap(int arr[], int size){
    for(int i = floor(size/2); i >= 1 ; i--){
    //iterates from through array by calling the percolate down function
        //to rearrange the array into a heap
        PercolateDown(arr, i, size);
    }
}

// This is the 'heapsort' function that sorts the array arr[] in *descending* order. 
// You may want to use the BuildHeap and DeleteMin functions in this function. 
void Heapsort(int arr[], int size){
    BuildHeap(arr, size); //builds the heap from the given array and size
    for(int i = size; i >= 1; i--){
    //iterates through the heap to repeatedly delete the min value,
        //arranging the array in descending order
        DeleteMin(arr, i);
    }
}

int main()
{
   cout << "Please enter the length (number of elements) of the input array: ";
   int size;
   cin >> size;

   if(size <= 0) {
      cout << "Illegal input array length!" << endl;
      return 0;
   }

   int* arr = new int[size+1];

   cout << "Please enter each element in the array" << endl; 
   cout << "(each element must be an integer within the range of int type)." << endl;
   for(int i = 1; i <= size; i++) {
      cout << "arr[" << i << "] = ";
      cin >> arr[i];
   }

   cout << "The input array arr[] is: "; 
   for(int i = 1; i < size; i++)
      cout << arr[i] << ",";
   cout << arr[size] << endl;

   Heapsort(arr,size); 

   cout << "After heapsort, the sorted array arr[] is: "; 
   for(int i = 1; i < size; i++)
      cout << arr[i] << ",";
   cout << arr[size] << endl;

   delete [] arr;

   return 0;
}

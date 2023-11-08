#include <iostream>

using namespace std;

// This function exchanges the values of var1 and var2.
void Swap(int& var1, int& var2){
    int temp = var1;
    var1 = var2;
    var2 = temp;
}

// This function uses the last element as the pivot element and 
// partitions the array arr[first..last] by rearranging the elements 
// and returning the (correct) position of the pivot, say q, so that 
// arr[x] <= arr[q] for all x < q, and arr[x] >= arr[q] for all x > q. 
// This function must to be implemented based on the Lomuto’s scheme.
int Partition(int arr[], int first, int last){
    int i = first-1; // starts i at first-1
    int pivot_val = arr[last]; //pivot value is the last value in the array
    //iterates through the array except for the last index, the pivot value
    for(int j = first; j < last; j++){
        //if statement increments i & swaps values in i & j if j < pivot
        if(arr[j] < pivot_val){
            i++; //increment i
            Swap(arr[i], arr[j]); //swaps i and j
        }
    }
    Swap(arr[i+1], arr[last]); //swaps i+1 and the pivot
    //returns the pivot position where the array would be partitioned at
    return i+1;
} 

// This is the 'quick sort' function that sorts the array arr[first..last] 
// in ascending order.
void Quicksort(int arr[], int first, int last){
    if(first < last){
        int pivot_position = Partition(arr, first, last);
        Quicksort(arr, first, pivot_position-1);
        Quicksort(arr, pivot_position+1, last);
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

   int* arr = new int[size];

   cout << "Please enter each element in the array" << endl; 
   cout << "(each element must be an integer within the range of int type)." << endl;
   for(int i = 0; i < size; i++) {
      cout << "arr[" << i << "] = ";
      cin >> arr[i];
   }

   cout << "The input arr[] is: "; 
   for(int i = 0; i < size-1; i++)
      cout << arr[i] << ",";
   cout << arr[size-1] << endl;

   Quicksort(arr,0,size-1); 

   cout << "After quicksort, the sorted array arr[] is: "; 
   for(int i = 0; i < size-1; i++)
      cout << arr[i] << ",";
   cout << arr[size-1] << endl;

   delete [] arr;

   return 0;
}

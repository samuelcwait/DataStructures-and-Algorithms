#include <iostream>

using namespace std; 

bool CheckPowerOfTwo(int n) {
   //TODO 
}

int main() {

   int val; 
   cout << "Enter an integer (0,1,...): "; 
   cin >> val;
 
   if (CheckPowerOfTwo(val)) {
      cout << "Power of two: true"; 
   } else {
      cout << "Power of two: false"; 
   }
   
   return 0;
}
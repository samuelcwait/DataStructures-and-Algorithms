#include <iostream>

using namespace std; 

bool CheckPowerOfTwo(int n) {
    if(n == 1 || n == 2){
        //base case checks to see if the value passed is 2^0 or 2^1
        return true;
    }
    else if(n < 1){
        //base case returns false if the value is negative or 0
        return false;
    }
    else if(n%2 == 1){
        //base case returns false if odd
        return false;
    }
    else{
        //recursive call, passing n/2 to the next recursive layer
        return CheckPowerOfTwo(n/2);
        //if n is odd, there is no way it can be a power of 2
        //if n is a power of 2 and is divided by 2 enough times it will eventually == 2
        //if n is not a power of 2 and is even, and is divided by 2 enough times,
        //then it will eventually == an odd number, returning false under the
        //n%2 == 1 base case. 
    }
}

int main() {

   int val; 
   cout << "Enter an integer (0,1,...): "; 
   cin >> val;
 
   if (CheckPowerOfTwo(val)) {
      cout << "Power of two: true\n";
   } else {
      cout << "Power of two: false\n"; 
   }
   
   return 0;
}


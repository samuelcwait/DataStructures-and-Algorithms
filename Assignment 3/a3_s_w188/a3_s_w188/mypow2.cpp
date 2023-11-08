#include <iostream>

using namespace std;

double ImprovedPow(double x, int n) {
    double y; //double since x is double for large values.
    if(n == 0){
        return 1; //same base case as mypow()
    }
    else if (n%2 == 1){
        //checks if n is odd, if it is then we recursively call the function
        //with x and (n-1)/2 so that we can divide the exponent by 2 and returning that
        //value into the variable y when the base case is reached. We then return
        //x*y*y, improving the efficiency of the function
        y = ImprovedPow(x, (n-1)/2);
        return x*y*y;
    }
    else{
        //checks if n is even, if it is then we recursively call the function
        //with x and n/2. Dividing the exponent by 2 and returning that
        //value into the variable y when the base case is reached then returning
        //x*y*y improves the efficiency of the function
        y = ImprovedPow(x, n/2);
        return y*y;
    }
}

int main() 
{
   cout << "To calculate x^n..." << endl;
	
   double x;
   int n;
   cout << "Please enter x: ";
   cin >> x;
   cout << "Please enter n: ";
   cin >> n;
   
   if(x == 0) {
      if (n > 0) {
         cout << 0 << endl;
      } else {
         cout << "x^n is not defined." <<endl;
      }
   } else {
      cout << ImprovedPow(x,n) << endl;
   }

   return 0;
}

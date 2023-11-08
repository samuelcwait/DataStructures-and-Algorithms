#include <iostream>

using namespace std;

double Pow(double x, int n) {
    if(n == 0){
    //base case, retruns 1 for n == 0 (x^0 == 1 for any x)
        return 1;
    }
    else{
        //if n != 0, we recursively call the function with x and n-1 until n==0.
        //once n == 0, we return 1 and ascend the recursive layers, multipying each
        //return value by x
        return x*Pow(x, n-1);
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
      cout << Pow(x,n) << endl;
   }

   return 0;
}



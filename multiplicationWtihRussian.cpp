#include<iostream>
using namespace std;

//Russion multiplication
//Let the two numbers to be multiplied be a and b.
//If a is zero then break and print the result.
//If a is odd then add b to the result.
//Half a, Double b. Goto Step 2.
int multiplication  (int a,int b) {
    int a;
    int b;
    int result = 0; 
    if (!a)  {
        return result;
    }
    while (a) {
        if (a & 1) {
            result += b;
        }
        //half a
        a >>= 1;

        //double b 
        b <<= 1;
    }
    return result;
}


int main()
{


    
}

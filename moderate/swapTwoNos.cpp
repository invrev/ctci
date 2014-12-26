#include<iostream>
using namespace std;


void swapTwoNos (int &a,int &b) {

    //note the thing (a^a) = 0 and (a^b^b) = a
    a = a ^ b; //con
    b = a ^ b; // a^b^b
    a = a ^ b; // a^b^a
}


int main () {

    int a = 10;
    int b = 20;
    cout << "(" << a << "," << b << ")" << endl;
    swap (a,b);
    cout << "(" << a << "," << b << ")" << endl;

}

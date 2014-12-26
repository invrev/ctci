#include<iostream>
using namespace std;

bool isPowerOfTwo (int n) {

    return ( (n & (n-1) ) == 0);

}

void test (int n) {
    if (isPowerOfTwo(n) == true) {
        cout <<  n << " is power of 2." <<  endl;
    } else {
        cout <<  n << " is not power of 2." <<  endl;
    }
}

int main () {
    test(4);
    test(16);
    test(1);
    test(17);

}

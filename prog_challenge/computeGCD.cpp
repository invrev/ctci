#include<iostream>
using namespace std;

//3,4 : 1
//5,3  : 1
//2,4  : 2
//3,3 : 3

int gcd(int m,int n) {

    if (m == 0 || n == 0) {
        return 0;
    }
    while (m != n) {
        if (m > n ) {
            m -= n;
        } else {
            n -= m;
        }
    }
    return m;
}

void test (int a,int b) {
    int result = gcd (a,b);
    cout << "the GCD (" << a << "," << b << ") = "  << result << endl;
}


int main () {
    test(4,0);
    test(4,3);
    test(3,4);
    test(3,3);
    test(5,3);
    test(12,4);
}

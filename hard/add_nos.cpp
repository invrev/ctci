#include<iostream>
using namespace std;


int addTwoNos (int &a,int &b) {
    while (b != 0) {
        int carry = (a & b);
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main () {

    int a = 3;
    int b = 2;
    cout << "the result = " << addTwoNos(a,b) << endl;

}

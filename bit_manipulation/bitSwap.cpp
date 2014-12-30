#include<iostream>
using namespace std;


int swapBits(int& input) {
   
    //NOTE : int 4 byte -> 1 Byte = 2 nibble = aa,55 
    int evenMask = 0xaa;
    int oddMask = 0x55;
    int no = sizeof(int);
    int cnt = no;
    while (cnt != 0) {
        evenMask |= (evenMask << 8);
        cnt = cnt - 1;
    }
    cnt = no;
    while (cnt != 0) {
        oddMask |= (oddMask << 8);
        cnt = cnt - 1;
    }
    int evenBits = input & evenMask;
    int odddBits = input & oddMask;
    int result = (evenBits >> 1) | (odddBits << 1);
    return result;
}

int main () {

    int input = 23;
    cout << "the result = " << swapBits(input) << endl;

}

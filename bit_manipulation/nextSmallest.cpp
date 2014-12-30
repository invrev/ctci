#include<iostream>
#include<limits.h>
using namespace std;


int countNumberofBits (int x) {
    int count = 0;
    while (x != 0) {
        x = x & (x-1);
        count++;
    }
    return count;
}


int nextSmallest (int x) {
    int counter = countNumberofBits(x);
    while (x < 0) {
        x = x - 1;
        int tmpCounter = countNumberofBits(x);
        if (tmpCounter == counter) {
            return x;
        }
    }
    return x;
}

int nextLargest(int x) {
    int counter = countNumberofBits(x);
    while (x < INT_MAX) {
        x = x + 1;
        int tmpCounter = countNumberofBits(x);
        if (tmpCounter == counter) {
            return x;
        }
    }
    return x;
}


int main () {

}

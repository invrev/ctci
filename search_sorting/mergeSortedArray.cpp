#include<iostream>
using namespace std;


void mergeTwoArrays(int a[],int m,int b[],int n) {
    //NOTE m > n
    //And m+n = sizeof(a)
    int index = m+n - 1;
    m = m - 1;
    n = n - 1;
    while (m != 0 || n != 0) {
        if (a[m] > b[n]) {
            a[index] = a[m];
            m--;
        } else {
            a[index] = b[n];
            n--;
        }
        index--;
    }
    while (n != 0) {
        a[index] = b[n];
        n--;
        index--;
    }

}


int main () {

}

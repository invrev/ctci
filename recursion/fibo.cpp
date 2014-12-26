#include<iostream>
using namespace std;

int genFibo (int n) {
    
    int first = 0;
    int second = 1;
    int result = first + second;
    //Use of windowing
    for (int i = 2;i<n;i++) {
       result = first + second;
       second = result;
       first= second;
    }
}

int main () {
    genFibo (3);
}

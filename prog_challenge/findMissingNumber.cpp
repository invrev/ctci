#include<iostream>
using namespace std;

int findMissingNumber (int a[],int n) {
    int result = 0;
    int x1 = 0;
    int x2 = 0;
    for (int i=0;i<l;i++) {
        x1 = x1 ^ a[i];
    }
    for (int i=1;i<=l+1;i++) {
        x2 ^= i;
    }
    result = x1 ^ x2 ;
    return result;
}

void test(int a[]) {

    int l = sizeof(a)/sizeof(a[0]);
    int missingNumber = findMissingNumber(a,l);
    cout << missingNumber << endl;
}

int main () { 
    int a [] = {1,2,3,4,5};
    test(a);
}

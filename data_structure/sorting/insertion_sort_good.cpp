#include<iostream>
using namespace std;

//Stable sort : O(n) : if elements are sorted else O(n^2) W.C.

void printArray(int a[],int n) {
    for (int i=0;i<n;i++) {
        cout << a[i] << ",";
    }
    cout << endl;
}


//1|3,4,2, | : position of i : 1 to n line # 22
//1,3|4,2,
//1,2,3|4,
//1,2,3,4|

void insertionSort(int a[],int n) {
    //0 to i-1 are sorted
    //shift a[i] down to its proper place in a[0..i]
    for (int i=1;i<n;i++) {
        //NOTE : j-1 : predecessor  j : current Index
        for (int j=i;j>0 && a[j-1] > a[j] ;j--) {
            swap(a[j-1],a[j]);
        }
        printArray(a,n);
    }
}


int main () {

    int a[] = {3,1,4,2};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(a,n);
    printArray(a,n);
}



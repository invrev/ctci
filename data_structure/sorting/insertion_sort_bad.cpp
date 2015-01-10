#include<iostream>
using namespace std;

//3,1,4,2
//3|1,4,2 
//3,1,4,2
//3,1,4,2
//3,1,4,2

void printArray(int a[],int n) {
    for (int i=0;i<n;i++) {
        cout << a[i] << ",";
    }
    cout << endl;
}

void insertionSort(int a[],int n) {

    //0 to i-1 are sorted
    //0-<<<-j-i-->>>--n
    //shift a[i] down to its proper place in a[0..i]
    for (int i=1;i<n;i++) {
        int tmpIndex = i ;
        for (int j=i-1;j>=0 ;j--) {
            //EXTRA if no ILP (Instruction Level Parallelism) ,BP fails
            if (a[j] > a[tmpIndex]) {
                swap(a[tmpIndex],a[j]);
                tmpIndex = j;
            } else {
                break;
            }
        }
    }
}


int main () {

    int a[] = {3,1,4,2};
    int n = sizeof(a)/sizeof(a[0]);
    insertionSort(a,n);
    printArray(a,n);
}



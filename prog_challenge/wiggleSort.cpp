#include<iostream>
#include<algorithm>
using namespace std;

//WiggleSort
//Given a sorted array, and re-arrange it to wiggle style in one pass.
//i.e. [1] A0 >= A1 <= A2 >= A3 .... .... An.
//     [2] A0 <= A1 >= A2 <= A3 .... .... An.

//Swap the neighbours

void WiggleSort(int a[],int n) {
    //sort the array
    sort(a,a+n);
    for (int i=1;i<n-1;i=i+2) {
        swap (a[i],a[i+1]);
    }
}


void WiggleSortWrong(int a[],int n) {
    //sort the array
    sort(a,a+n);
    for (int i=0;i<n-1;i++) {
        swap (a[i],a[i+1]);
    }
    swap (a[n-1],a[n-2]);
}


int main () {
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);
    WiggleSort(a,n);
    //WiggleSortI (a,n);
    for (auto &it:a) {
        cout << it << ",";
    }
    cout << endl;

}

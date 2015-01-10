#include<iostream>
using namespace std;

//55,41,59,26,53,58,97,93

void printArray(int a[],int n) {
    for (int i=0;i<n;i++) {
        cout << a[i] << ",";
    }
    cout << endl;
}
//left <= pivotV > right
int partition (int a[],int start,int end) {
    int pivotV = a[--end];
    int left = start - 1;
    for (int i=start;i<end;i++) {
        if (a[i] <= pivotV) {
            //j++;
            swap(a[i],a[++left]);
        }
    }
    //Increase the left and then replace with the pivotIdx
    swap(a[++left],a[end]);
    return left;
}

void quickSort(int a[],int start,int end) {
    if (start < end) {
        int pivotIdx = partition(a,start,end);
        quickSort (a,start,pivotIdx-1);
        quickSort (a,pivotIdx+1,end);
    }
}


int main () {

    //3,1,4,2
    int a[] = {3,1,4,2};
    int n = sizeof(a)/sizeof(a[0]);
    int start = 0;
    quickSort(a,start,n);
    printArray(a,n);
}

#include<iostream>
using namespace std;

void printArray(int a[],int n) {
    for (int i=0;i<n;i++) {
        cout << a[i] << ",";
    }
    cout << endl;
}
//Idea : to use the 2 idx pointer instead of 2 inoder to avoid 
//unnecessay swaps

//start                             end
//pivotV    <= pivotV    ???????? >pivotV


void quickSort (int a[],int start,int end) {
    if (start >= end) {
        return ;
    } 
   
    //Get random pivot and create randomized quick sort 
    //int m = rand() % (right-left+1);
    //swap(vec[start], vec[start+m]);
    
    int pivotV = a[start];

    int left = start;
    int right = end+1;
    while (true) {
        do {
            left++;
        } while (left <= end && a[left] < pivotV);

        do {
            right--;
        } while (a[right] > pivotV);

        if (left > right) {
            break;
        }
        swap(a[left],a[right]);
    }
    swap(a[start],a[right]);
    quickSort (a,start,right-1);
    quickSort (a,right+1,end);
}



int main () {

    //3,1,4,2
    int a[] = {3,1,4,2};
    int n = sizeof(a)/sizeof(a[0]);
    int start = 0;
    quickSort(a,start,n-1);
    printArray(a,n);
}

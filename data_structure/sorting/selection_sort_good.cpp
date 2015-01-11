
#include<vector>
using namespace std;

//Select min from input vector
//for each i from 0 to n-2, 
//find the smallest element in the suffix A[i..n-1] 
//and swap that element with A[i]
void selectionSort (vector<int>& A) {
    int m = A.size();
    int minIndex = 0;
    for (int i=0;i<m-1;i++) { //Iterate over 0 to m-1
        minIndex = i;
        for (int k=i+1;k<m;k++) {
            if (A[k] < A[minIndex]) {
                minIndex = k;
            }
        }
        if (minIndex != i) {
            swap(A[minIndex],A[i]);
        }
    }
}

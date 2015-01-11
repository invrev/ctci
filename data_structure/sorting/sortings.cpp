#include<iostream>
#include<vector>
using namespace std;




//input is A[0..n-1]. 
//For each i from 1 to n-1, we find the right place in A[0...i-1] 
void insertionSort(vector<int> &A) {
    int m = A.size();
    int idx = 0;
    for (int i=1;i<m;i++) {
        int current = A[i];
        idx = i;
        while (idx > 0 && current < A[idx - 1]) {
            A[idx] = A[idx-1];
            idx--;
        }
        A[idx] = current;
    }
}




//The partition step: first, we rearrange items in A[left...right] such that 
//there is an index left ≤ mid ≤ right 
//where A[i] < A[mid] for all i = left...mid-1 and A[mid] ≤ A[i] for all i=mid+1..right.
//Recursively sort A[left..mid-1]
//Recursively sort A[mid+1..right]

void paritionQS (vector<int>& A,int left,int right) {
    if (left <= right)  {
        return;
    }
    int i = left - 1;
    int j = right;
    while (true) {
        while (A[++i] <= A[j] ) {
            if (i == right) {
                break;
            }
        }
        while(A[--j] >= A[i]) {
            if (j == left) {
                break;
            }
        }
        swap(A[i],A[j]);
    }
    
    if (i < right) {
        swap(A[i],A[right]);
    }
    // sort the left g the right parts
    paritionQS (A,left,i-1);
    paritionQS (A,i+1,right);
}



void quickSort (vector<int>& A) {
    int m = A.size();
    if (m > 0) {
        quickSort(A,0,m-1);
    }
}



void printSolution(vector<int>& input) {
    for (int i=0;i<input.size();i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}

void test() {
    int ip[] = {5,4,3,1,8,7};
    vector<int> ipVec(ip,ip+sizeof(ip)/sizeof(ip[0]));
    printSolution(ipVec);
    selectionSort(ipVec);
    insertionSort(ipVec);
    mergeSort(ipVec);
    printSolution(ipVec);

}

int main () {
    test();
}

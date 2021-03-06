#include<iostream>
using namespace std;

//In heap sort 2 main important things 
//1.shape (balanced array with left and right child at same level while parent is at 1 level up) 
//2.property  (parent is always larger than its children)

void printHeap(int A[],int n) {
    for (int i=0;i<n;i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int getParent (int n) {
    return (n/2);
}

int getLeftChild (int n) {
    return (2 * n);
}

int getRightChild(int n) {
    return (2 * n) + 1;
}

//siftup
void maxHeapify(int A[],int i,int n) {
    int l = getLeftChild(i);
    int r = getRightChild(i);
    int largest = i;
    if (l <= n && A[l] > A[i]) {
        largest = l;
    } 
    if (r <= n && A[r] > A[largest]) {
        largest = r;
    } 
    if (largest != i) {
        swap (A[i],A[largest]);
        maxHeapify (A,largest,n);
    }
}


void buildMaxHeap (int A[],int n) {
    printHeap(A,n);
    //start from second last nodes
    for (int i= (n/2);i>=1 ;i--) {
        maxHeapify(A,i,n);
        //printHeap(A,n);
    }
    //printHeap(A,n);
}


void minHeapify(int A[],int i,int n) {
    int leftChild = getLeftChild(i);
    int rightChild = getRightChild(i);
    int smallest = i;
    if (leftChild <= n && A[leftChild] <  A[i]) {
        smallest = leftChild;
    } 
    if (rightChild <= n && A[rightChild] < A[smallest]) {
        smallest = rightChild ;
    } 
    if (smallest != i) {
        swap (A[i],A[smallest]);
        minHeapify (A,smallest,n);
    }
}


void buildMinHeap (int A[],int n) {
    printHeap(A,n);
    //start from second last nodes
    for (int i= (n/2);i>=1 ;i--) {
        minHeapify(A,i,n);
        printHeap(A,n);
    }
    printHeap(A,n);
}

void heapSort(int a[],int n) {
    buildMaxHeap (a,n-1);
    for (int i=n-1;i>=1;i--) {
        swap(a[i],a[1]);
        maxHeapify(a,1,i-1);
    }
}

int main () {
    int A[] = {-1,4,3,2,16,9,10,14,8,7};
    int n = sizeof(A)/sizeof(A[0]);
    //buildMinHeap (A,n-1);
    //buildMaxHeap (A,n-1);
    heapSort (A,n);
    printHeap(A,n);

}

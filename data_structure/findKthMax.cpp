#include<iostream>
#include<limits.h>
using namespace std;

int partition (int a[],int start,int end,int k) {
    if (start < end)  {
        int pivot = start-1;
        int ele = a[--end];
        for (int i=start;i<end;i++) {
            if (a[i] <= ele) {
                swap(a[++pivot],a[i]);
            }
        }
        swap(a[++pivot],a[++end]);
        //cout << "p = "  << pivot << ","  << "e=" << end<< endl;
        if ( k == pivot ) {
            return a[pivot];
        } else if (k < pivot) {
            partition (a,start,pivot-1,k);
        } else if (k > pivot) {
            partition (a,pivot+1,end,k);
        }  
    }
}

int findKthLargestElement (int a[],int n,int k) {

//Sort and then return kth largest element O(n log n) + O(1)

//Parition the array at aribitary position and I would get the 
//partion index then Comapre that parition idex with k and will move accoridingly 
    return 0;
}

int main () {

    int k = 3;
    int a[] =  {3,2,9,18,6,27,40};
    int n = sizeof(a)/sizeof(a[0]);
    int p = partition (a,0,n,k);
    cout << "the part " << p << endl;
}

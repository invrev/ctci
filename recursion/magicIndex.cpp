#include<iostream>
#include<limits.h>
using namespace std;


//Find magic index s.t. A[i] == i
//It runs in O(n)
int findMagicL (int A[],int n) {
    
    for (int i=0;i<n;i++) {
        if ( A[i] > 0 && (A[i] ^ i == 0) ) {
            return i;
        }
    }
    return INT_MIN;
}

//can we optimize it to O(log n)
int findMagicBin (int a[],int n) {
    int start = 0;
    int end = n-1;
    while (start < end) {
        int mid = start + (end - start)/2;
        if (a[mid] == mid) {
            return mid;
        } else if (a[mid] < mid) {
            start = mid + 1;
        } else if (a[mid] > mid) {
            end = mid - 1;
        }
    }
    return INT_MIN;
}

int findMagicBinR (int a[],int start,int end) {
    if ( (end - start >= 1) ) {
        int mid = start + (end - start) /2;
        if (a[mid] == mid) {
            return  mid;
        } else if (a[mid] > mid) {
            return findMagicBinR (a,start,mid-1);
        } else {
            return findMagicBinR (a,mid+1,end);
        }
    } else {
        return INT_MIN;
    }
}


//What if elements are not distinct
//Bin search  work on index 
int findMagicRND (int a[],int len,int start,int end) {
    if ( end > len || start < 0 || end - start < 1) {
        return INT_MIN;
    } else {
        int mid = start + ( (end - start)/2 );
        if (a[mid] == mid) {
            return mid;
        } 
        //check between start and left
        int left = min(mid-1,a[mid]);
        int lIndex = findMagicRND (a,len,start,left);
        if (lIndex != INT_MIN)  {
            return lIndex;
        }
        //Check between right and end
        int right = max(mid+1,a[mid]);
        int rIndex = findMagicRND (a,len,right,end);
        if (rIndex != INT_MIN) {
            return rIndex;
        }
        return INT_MIN;
    }

}



int main () {

    int A[] = {-1,0,2,33,44,55};
    int n = sizeof(A)/sizeof(A[0]);
    int r = findMagicBin (A,n);
    cout << "the result = " << r << endl;
    r = findMagicL (A,n);
    cout << "the result = " << r << endl;
    r = findMagicRND(A,n,0,n-1);
    cout << "the result = " << r << endl;
}

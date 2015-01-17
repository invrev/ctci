#include<iostream>

//1 2 3        7 4 1  
//4 5 6   ==>  8 5 2     
//7 8 9        9 6 3   

//9 6 3        7 4 1
//8 5 2    ==> 8 5 2
//7 4 1        3 6 9 
//Not in place with extra space O(n^2)

void rotateMatrixBy90deg (int a[][3],int m,int n) {
    
    //Diagonal elements
    for (int i=0;i<n-1;i++) {
        for (int j = 0;j<n-1-i;j++) {
           swap(a[i][j],a[n-1-j][n-1-i]);          
        }
    }
    //Horizontal movement
    for (int i=0;i<n/2;i++) {
        for (int j=0;j<n;j++) {
            swap(a[i][j],a[n-1-i][j]);
        }
    }
}

//for (int i=0;i<n;i++) {
//    int t = n-1;
//    for (int j = n-i,k=i;j>=0;j--,k++) {
//       swap(a[i][j],a[t][k]);          
//    }
//}

//for (int i=0,k=n-1;i<n/2;i++,k--) {
//  for (int j=0;j<n;j++) {
//     swap(a[i][j],a[k][j]);
//  }
//}

#include<iostream>
using namespace std;

//1 2 3
//4 5 6 
//7 8 9

bool search2DHelperRow (int a[][],int i,int j,int key) {
    
    while ( i >= 0 && a[i--][j] == key) {
        return true;
    }
    return false;
}

bool search2DHelperCol (int a[][],int i,int j,int m,int key) {
    while (j <= m && a[i][j++] == key) {
        return true;
    }
    return false;
}

bool search2dArray ( int a[][],int m,int n,int key) {
    
    for (int i=0;i<m;i++) {
         for (int j=n-1-i;j>=0;j--) {
             if (a[i][j] == key ) {
                 return true;
             } 
             if (a[i][j] < key) {
                 //search column
                 if ( search2DHelperCol(a,i,j,m,key) ) {
                     return true;
                 }
             } else {
                  //search Row
                  if ( search2DHelperRow(a,i,j,key) ) {
                     return true;
                 }
             }
             
         } 
    }
    
    return false;

}

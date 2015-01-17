#include<iostream>
//Move all 1010101000 0's to the begining

void moveAllNumbersToStart (int a[],int n,int key) {

    int prev = -1;
    int start = 0;
    while (start < n) {
        if (a[start] == key) {
            swap(a[++prev],a[start]);
            //start -= 1;
        }
        start++;
    }
} 
//10101010000 : 01 101010000
//011 01010000
//0011 1010000

#include<iostream>
#define MAX_COL 20
using namespace std;

void paintFill(int grid[][MAX_COL],int m,int n,int row,int col,int newColor) {

    if (m < 0 || n < 0 || m > row || n > col) {
        return;
    } else {

        int rowVec[] = {1,-1,0,0} ;
        int colVec[] = {0,0,1,-1};
        int l = sizeof(rowVec)/sizeof(rowVec[0]);
        if (grid[row][col] != newColor) {
            grid[row][col] = newColor;
        }
        for (int i=0;i<l;i++) {
            if (grid[row+rowVec[i]][n+colVec[i]] != newColor) {
                paintFill(grid,m,n,row+rowVec[i],col+colVec[i],newColor);
            }
        }
    }

}

int main () {

}

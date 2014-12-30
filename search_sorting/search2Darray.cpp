#include<iostream>
#include<vector>
using namespace std;

bool search2DBin() {
    
    
    return false;
}


bool searchinRow(vector<vector<int> >&grid,int row,int startCol,int endCol,int key) { 
    
    while (startCol < endCol) {
        int midCol = startCol  +  ( (endCol - startCol) / 2) ;
        if  (grid[row][midCol] == key) {
            return true;
        } else  if (grid[row][midCol] < key) {
            startCol = midCol + 1;
        } else {
            endCol = midCol - 1;
        }
    }
    return false;
}


bool searchinCol(vector<vector<int> >&grid,int col,int startRow,int endRow,int key) { 
    while (startRow < endRow) {
        int midRow = startRow  +  ( (endRow - startRow) / 2) ;
        if  (grid[row][midRow] == key) {
            return true;
        } else  if (grid[row][midRow] < key) {
            startRow = midRow + 1;
        } else {
            endRow = midRow - 1;
        }
    }
    return false;
}


bool search2DNonDia(vector< vector<int> >&grid,int key) {
    int n = grid.size();
    for (int j=n-1,i=0;j>=0;j--,i++) {
        if (grid[i][j] < key) {
            //bin search in row //row,col:(i,j)
            if (searchinRow (grid,j,i,n-1,key) == true) {
                return true;
            }
        } else {
            //bin search in  column
            if (searchinCol(grid,i,0,j,key) == true) {
                return true;
            }
        }
    }
    return false;
}

bool search2DLin (vector< vector<int> >&grid,int key) {
    int m = grid.size();
    if ( m > 0) {
        int n = grid[0].size();
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] == key) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main () {

}

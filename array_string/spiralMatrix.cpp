#include<iostream>

void printSpiralMatrix (vector<vector> grid) {

    int m = grid.size();
    int row = 0;
    int col = -1; // not 0
    if (m > 0) {
        int n = grid[0].size();
    } else {
        return;
    }
    while (true)  {
        for (int i=0;i<n;i++) {
            cout << grid[row][++col] << " ";
        }
        m = m -1;
        if (m == 0) {
            break;
        }
        for (int i=0;i<m;i++) {
            cout << grid[++row][col] << " " ;
        }
        n = n - 1;
        if (n == 0) {
            break;
        }
        for (int i=0;i<n;i++) {
            cout << grid[row][--col] << " ";
        }
        m = m -1;
        if (m == 0) {
            break;
        }
        for (int i=0;i<m;i++) {
            cout << grid[--row][col] << " ";
        }
        n = n -1;
        if (n == 0) {
            break;
        }
    }

}

int main () {

}

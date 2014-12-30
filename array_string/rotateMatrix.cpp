#include<iostream>
using namespace std;

void rotateNbyNby90 (vector< vector<int> >& grid) {

    //diagonal swap
    int n = grid.size();
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i;j++) {
            swap(grid[i][j],grid[len-1-j][len-1-i]);
        }
    }

    //horizontal swap
    for (int i=0;i<n/2;i++) {
        for (int j=0;j<len-1;j++) {
            swap(grid[i][j],[n-1-i][j]);
        }
    }
}

int main () {
    
}

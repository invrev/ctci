#include<iostream>
#include<vector>
using namespace std;


int noOfWaysToXY(vector< vector<int> >&grid) {

    int m = grid.size();
    if (m > 0) {
        int n = grid[0].size();
        vector<vector <int> > path (m+1,vector<int>(n+1,0));
        path[0][1] = 1;
        //traverse on the grid
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                //1 : indicates block 
                if (grid[i-1][j-1] != 1) {
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
            }
        }
        return (path[m][n]);
    }
    return 0;
}

int main () {

}

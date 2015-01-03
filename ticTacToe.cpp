#include<iostream>
#include<utility>
#include<vector>
using namespace std;


bool whoIsWinner (vector< vector<int> >& board,int cross,int circle) {
    int m = board.size();
   
    //check the each row

    int start = 0;
    int end = n-1;
    //check row
    for (int i=0;i<m;i++) {
        start = 0;
        end = n -1;
        while (start < end) {
            if (a[i][start++] != a[i][end--]) {
                break;
            }
        }
        if ( (start - end == 1) && a[i][start] == a[i][start+1]){
            cout << "winner found" << endl;
        }
    }
    //check col
    for (int j=0;j<n;j++) {
        start = 0;
        end = m -1;
        while (start < end) {
            if (a[start++][j] != a[end--][j]) {
                break;
            }
        }
        if ( (start - end == 1) && a[start][j] == a[start+1][j]){
            cout << "winner found" << endl;
        }
    }
    //check diagonal
    for (int i=0,j=0;i<m;i++,j++) {
        if (a[i][j] != a[m-1-i][n-1-j]) {
            break;
        }
    }
    //check antidiagonal or secondary diagonal
    for (int i=0,j=0;i<m;i++,j++) {
            if (a[i][n-1-j] != a[m-1+i][j]) {
                break;
            }
    }



    return true;
}



int main () {
    vector < vector<pair<int,int> > > board (n+1,-1);

}

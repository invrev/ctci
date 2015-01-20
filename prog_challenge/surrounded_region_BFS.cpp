#include<iostream>
#include<vector>
using namespace std;



//BFS visit all neighbours
//If 'O' / 'I'
//Idea : from the point 'O' if you reach to any point using BFS with 'O' then change it to 'I'
//In the end ,traverse all the grid and convert 'I' to 'O' and 'O' to 'X'
//NOTE : instead of storing x and y seperately it stores x*n + y and retreive x = (result)/n , y = result % y
void visit (queue<int>& visit_q,vector<vector<char> > &board,int i,int j) {
    int m = board.size();
    if (m == 0) {
        return ;
    }
    int n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
        return;
    }
    int ele =  i*n + j;
    visit_q.push(ele);
    board[i][j] = 'I';
}
void bfs (vector<vector<char> > &board,int i,int j,queue<int>& visit_q) {
    
    int m = board.size();
    int n = board[0].size();
    visit (visit_q,board,i,j);
    while (!visit_q.empty()) {
        int row_col = visit_q.front();
        visit_q.pop();
        int row = row_col / n;
        int col = row_col % n;
        visit(visit_q,board,(row+1),col);
        visit(visit_q,board,(row-1),col);
        visit(visit_q,board,row,(col-1));
        visit(visit_q,board,row,(col+1));
    }
    
}
void solve(vector<vector<char> > &board) {
    int m = board.size();
    if (m <= 2 ) {
        return ;
    }
    int n = board[0].size();
    if (n <= 2) {
        return ;
    }
   
    queue<int> visit_q;
    //traverse to left and right
    for (int i=0;i<m;i++) {
        if (board[i][0] == 'O') {
            bfs(board,i,0,visit_q);
        }
        if (board[i][n-1] == 'O') {
            bfs(board,i,n-1,visit_q);
        }
    }
    //traverse to top and bottom
    for (int i=1;i<n-1;i++) {
        if (board[0][i] == 'O') {
            bfs(board,0,i,visit_q);
        }
        if (board[m-1][i] == 'O') {
            bfs(board,m-1,i,visit_q);
        }
    }
    for(int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (board[i][j] == 'I') {
                board[i][j] = 'O';
            } else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

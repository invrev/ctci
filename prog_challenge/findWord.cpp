#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//Find WORD in the grid same idea as topological SORT iterate over all and do the DFS for all
//
void findWord(char grid[3][3],int x,int y,string &result
            ,vector<string>&op,bool visited [3][3] , unordered_set<string>& wordDict ) {
        int m = 3;
        int n = 3;
        int row[] = {1,-1,0,0,1,-1,1,-1};
        int col[] = {0,0,1,-1,-1,-1,1,1};
        int len = sizeof(row)/sizeof(row[0]);
        //if (x < 0 || y < 0 || x >= m || y >= n) {
        //    return;
        //}
        if (wordDict.find(result) != wordDict.end() ) {
            cout << result << endl;
            op.push_back(result);
            return;
        }
        //result.push_back(grid[x][y]);
        result += grid[x][y];
        visited[x][y] = true;
        for (int i=0;i<len;i++) {
            int tx = x+row[i];
            int ty = y+col[i];
            if (tx >= 0 && ty >= 0 && tx < m && ty < n) {
                if (visited[tx][ty] == false) { 
                    findWord(grid,tx,ty,result,op,visited,wordDict);
                }
            }
        }

    //for (int row=x-1; row<=x+1 && row<m; row++) 
    //  for (int col=y-1; col<=y+1 && col<n; col++) 
    //    if (row>=0 && col>=0 && !visited[row][col]) {
    //        findWord(grid,row,col,result,op,visited,wordDict);
    //    }

        visited[x][y] = false;
        result.pop_back();
}

void printWords (char grid[3][3],unordered_set<string> &u_set) {

    int M = 3;
    int N = 3;
    bool visited[3][3] = { {false} };
    vector<string> op;
    string result = "";
    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            findWord(grid,i,j,result,op,visited,u_set);
        }
    }
    
}


int main () {
    char grid[][3] = {{'G','I','Z'},
                         {'U','E','K'},
                        {'Q','S','E'}};
    string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
    int len = sizeof(dictionary)/sizeof(dictionary[0]);
    unordered_set<string> u_set;
    for (int i=0;i<len;i++) {
        u_set.insert(dictionary[i]);
    }
    printWords (grid,u_set);
}

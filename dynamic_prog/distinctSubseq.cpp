#include<iostream>
#include<string>
using namespace std;

//Modification of edit distance only considers 1.deletes and 2.matches
int numDistinct(string S, string T) {
    int m = T.length();
    int n = S.length();
    if (m > n) { 
        return 0;    
    }   // impossible for subsequence
    vector<vector<int>> path(m+1, vector<int>(n+1, 0));

    for (int k = 0; k <= n; k++)  {
        path[0][k] = 1;    
    }           // initialization

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            path[i][j] = path[i][j-1] + (T[i-1] == S[j-1] ? path[i-1][j-1] : 0);
        }
    }
    return path[m][n];
}


int main () {
    string s = "rabbbit";
    string t = "rabbit";
    int noWays = numDistinct (s,t);

    cout << "# of distinct ways " << noWays  << endl;
}


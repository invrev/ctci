#include<iostream>
#include<string>
using namespace std;

//
//1,6 => 1,1 | 1,2 | 2,2 | 1,3 | 2,3 and so on
//palidrome find start and maxLen and return
//NOTE : Zig Zag traversal
string findLongestPalidrome (string s) {

    int m = s.length();
    bool p[m][m] = { {false} };
    int maxLen = 0;
    int start = 0;
    for (int i=0;i<m;i++) {
        for (int j=0;j<=i;j++) {
          if (s[i] == s[j] &&  ( (j-i) == 1 || p[j+1][i-1]) ) {
              start = i;
              maxLen = j - i + 1;
              p[i][j] = true;
          }   
        }
    }
    
    return s.substr(start,maxLen);
}

int main () {

}

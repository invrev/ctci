#include<iostream>
#include<string>
using namespace std;

//initialize 2-d array for palindrome and 1-d array to store the all the cut count
//bottom up 
//aaba
//  a a b a
//a
//a
//b
//a
int findMinCut (string ip) {
    int m = ip.length();
    int D[m+1]; 
    
    for (int i=m;i>=0;i--) {
        D[i] = m-i;
    }
    
    int p[m][m] = { {false} };
    
    //Idea : if (3,6) is palidrome iff s[3] == s [6] && p[4][5] is palindrome
    for (int i=m-1;i>=0;i--) {
       for (int j=i;j<m;j++) {
        if (s[i] == s[j] && (j-i == 1 || p[i+1][j-1])) {
            p[i][j] = true;
            D[i] = min (D[i],D[j+1] + 1);
        }   
       }
    }
    return D[0] - 1;
}

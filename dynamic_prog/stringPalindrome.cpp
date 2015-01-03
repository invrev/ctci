#include<iostream>
#include<string>
using namespace std;

//Longest palindorme substring with DP with ZIGZAG traversal
void longestPalindromeSubstring (string &s) {
    int l = s.size();
    int p[l][l];

    int maxPalLen = 0;
    int start = 0;
    int end = 0;
    //perform zig zag check 
    for (int j=0;j<l;j++) { //End of string

        for (int i=0;i<j;i++) { //start of string
            //j-i : # of chars between the 2 ends of the string
            if (s[i] == s[j] && ( (j-i) <= 1  || p[i+1][j-1] == 1) ) {
                p [i][j] = 1;
            } else {
                p [i][j] = 0;
            }
            if ( p[i][j] && maxPalLen < (j-i)+1 ) {
                maxPalLen = (j-i)+1;
                //j : end i : start  (j-i) > 1
                start = i;
                end = j;
            }
            p[j][j] = 1;
        }
    }
    
    cout <<  "(" << start << "," << end  << ") = " << maxPalLen << endl;
    cout <<  s.substr(start,end-start+1) << endl;

}

int main () {

    string ip = "sabbap";
    longestPalindromeSubstring (ip);

}

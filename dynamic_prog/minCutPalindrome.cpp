#include<iostream>
#include<string>
using namespace std;


void minPalindromeCut(string &s) {

    int n = s.size();
    //Keeps track of # of splits needed
    //Base case i.e. for complete palindrome string it is  0
    int opt[n+1];

    bool p[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            p[i][j] = false;
        }
    }
    
    for (int i=0;i<=n;i++) {
        opt[i] = n - i;
    }

    //Go bottom traversal
    //We can to top down with reverse in the values in the opt array
    for (int i=n-1;i>=0;i--) {
        for (int j=i;j<n;j++) {
           if (s[i] == s[j] &&  ( (j-i) <= 1 || p[i+1][j-1])  ) {
               p[i][j] = true;
               //for eg. base case b[j+1] : last element = 0 
               opt[i] = min(opt[i],opt[j+1] + 1);
           }
        }
    }
    
    //as opt[j+1] + 1 so opt[0] - 1
    cout << opt[0] - 1  << endl;

    //using the opt array to recover the palindromes how ?

    cout << endl;
    

}

int main () {
    
    string ip = "saabap";
    minPalindromeCut (ip);

}

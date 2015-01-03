#include<iostream>
#include<string>
using namespace std;

//Longest palndrome substring
//Longest palndrome subsequence
//Permutation
//Matrix multiplication
//Scheduling
//Rod cutting
//One directional TSP


//abba,aba,abbca
bool isPaindrome(string &ip) {
    int end = ip.length();
    int start = 0;
    while (start < end) {
        if (ip[start++] != ip[--end]) {
            return false;
        }
    }
    return true;
}


void longestPalindromeSubstring(string &ip) {

}




void test (string input) {
    if ( true == isPaindrome (input) ) {
        cout << input << " is palindrome." << endl;
    } else {
        cout << input << " is not palindrome." << endl;
    }
}

int main () {

    test ("abba");
    test("aba");
    test("abbca");
}



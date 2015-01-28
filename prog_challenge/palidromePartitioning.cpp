#include<string>
#include<iostream>
using namespace std;


bool isPalindrome (string &s,int start,int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

void enumPalindromeParition (string &input,int k,vector<string>& result
        ,vector<vector<string> >& op) {
    
    int m = input.size();
    if (k == m) {
        op.push_back(result);
        return;
    }
    
    for (int i=k;i<m;i++) {
        if ( isPalindrome(input,k,i) ) {
            result.push_back(input.substr(k,i-k+1));
            enumPalindromeParition(input,i+1,result,op);// verify k+1 or i+1 (end+1 for next palindrome)
            result.pop_back();     
        }
    }
}

int main () {

}

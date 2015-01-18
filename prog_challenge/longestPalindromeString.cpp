#include<iostream>
#include<string>
using namespace std;

//to compute the max palindrome
//abcde
//abcd
//bcd
//abc
//bc
//c
void generateAllString () {
    string resultStr = "abcde";
    int n = resultStr.length();
    for (int i=n-1;i>=2;i--) {
        for (int start = 0;start<n-i;start++) {
            int end = start + i - 1;
            //cout << resultStr.substr(start,end-start+1) << endl;
            cout << resultStr.substr(start,i-start+1) << endl;
        }
    }
}

string longestPalindrome(string s) {
   int start = 0, end = 0;
   int maxLen = 0;
   int mid = 0;
   for (int i = 0; i < s.length(); i++) {
      int len1 = expandAroundCenter(s, i, i);
      int len2 = expandAroundCenter(s, i, i + 1);
      int len = max(len1, len2);
      if (len > maxLen) {
        mid = i;
        maxLen = len;
      }
   }
   
  start = mid - (maxLen-1)/2;
  return s.substr(start, maxLen);
}

int expandAroundCenter(string s, int start, int end) {
   int m = s.length();
   while (start >= 0 && end < m && s[start] == s [end]) {
       start--;
       end++; 
   }
   return end - start - 1;
}


int main () {

}

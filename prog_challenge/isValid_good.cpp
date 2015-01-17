#include<iostream>
#include<algorithm> //transform
#include<string> 

using namespace std;

bool isValidChar (char& input) {
       if (input >= 'a' && input <= 'z')
           return true;     
       if (input >= 'A' && input <= 'Z')
           return true;  
      if (input >= '0' && input <= '9')
           return true;  
   }


bool isPalindrome (string s) {
    transform(s.begin(),s.end(),s.begin(),::tolower);
    int end = s.length() - 1;
    int start = 0;
    while (start < end) {
        while (start < end && !isValidChar(s[start]) ) {
            start++;
        }
        while (start < end && !isValidChar(s[end]) ) {
            end--;
        }
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

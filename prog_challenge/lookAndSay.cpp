#include<iostream>
#include<string>
using namespace std;

//look and say

//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.

//1211 % 10 = 1
//1211/ 10 = 121

//121 12 1
//1%10 = 1
//1 to n

string countAndSay (int n) {
    
    string res = "1";    

    if (n == 0) {
        return "";
    }
    if (n == 1) {
       return res;
    }
    string tmp = "";
    for (int i=1;i<n;i++) {
        int l = res.length();
        int cnt = 1;
        for (int j=0;j<l;j++) {
            cnt = 1;
            while (j+1 < l && res[j] == res[j+1]) {
                cnt++;
                j++;
            }
            tmp += to_string (cnt) + res[j];
        }
        //res.clear();
        res = tmp;
        tmp.clear();
    }
   return res;
}

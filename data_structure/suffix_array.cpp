#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//Problem : To find the longest repeated sub-string
//eg.abcbabc
//Data structure solution : use suffix array
//given string : banana
//suffix array : banana,anana,nana,ana,na,a
int getCommonLen (string &a,string &b) {
    int m = a.length();
    int n = b.length();
    int tLen = min(m,n);
    int retLen = 0;
    for (int i=0;i<tLen;i++) {
        if (a[i] != b[i]) {
            return retLen;
        } 
        retLen++;
    }
    return retLen;
}

void printArray (vector<string> &ip) {
    int len = ip.size();
    for (int i=0;i<len;i++) {
        cout << ip[i] << "," ;
    }
    cout << endl;
}
//max T(n) =O(n log n)
string getMaxRepeatedSubstring (string &ip) {
    int maxLen = 0;
    vector <string> suffixArray;
    int len = ip.size();
    for (int i=len,start=0;i>0;i--,start++) {
        string tmp = ip.substr(start,i);
        //cout << tmp << endl;
        suffixArray.push_back(tmp);
    }
    printArray(suffixArray);
    sort(suffixArray.begin(),suffixArray.end());
    int sLen =  suffixArray.size();
    int mostCommonStrIdx = 0;
    for (int i=0;i<sLen-1;i++) {
        int tmpLen = getCommonLen(suffixArray[i],suffixArray[i+1]);
        if (maxLen < tmpLen) {
            maxLen = tmpLen;
            mostCommonStrIdx = i;
        }
    }
    //cout << "longest common string = " << suffixArray[mostCommonStrIdx] << endl;
    return suffixArray[mostCommonStrIdx] ;
}

void test (string ip) {
    string maxStr = getMaxRepeatedSubstring (ip);
    cout << "string = " << ip << ",maxRepeated str = " << maxStr << endl;
}

int main () {
    test ("banana");
    test ("abcbabc");
}


#include<iostream>
#include<string>
using namespace std;

//given: s1 = "aabcc", s2 = "dbbca",
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.

bool isInterleaving (string s1,string s2,string s3) {
    
    int m = s1.length();
    int n = s2.length();
    int o = s3.length();
    if ( m+n != o) {
        return false;
    }
    //Get base condition right please refer scrambling of string
    if (m == n && n == o && o == 0) {
        return true;
    }
    //bool result =  ( s1[0] == s3[0] ? true : false)  && isInterleaving (s1.substr(1,m-1),s2,s3.substr(1,o-1));
    //bool result1 = ( (s2[0] == s3[0] ? true : false)  
    //            && isInterleaving (s1,s2.substr(1,s2.length() - 1),s3.substr(1,s3.length() -1)) );

    bool result =  ( s1[0] == s3[0])  && isInterleaving (s1.substr(1,m-1),s2,s3.substr(1,o-1));
    bool result1 = ( (s2[0] == s3[0] )  
                && isInterleaving (s1,s2.substr(1,n-1),s3.substr(1,o-1)) );
    return (result || result1 );
}

void test(string s1,string s2,string s3) {
    bool result = isInterleaving (s1,s2,s3);
    if (result) {
        cout << "found interleaving " << s1 << "," << s2 << "," << s3 << endl;
    } else {
        cout << "not found " << s1 << "," << s2 << "," << s3 << endl;
    }
}

int main () {

    //bool result = isInterleaving ();
    test("aabcc","dbbca","aadbbbaccc");
    test("aabcc","dbbca","aadbbcbcac");
}


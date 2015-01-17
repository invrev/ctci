#include<iostream>
#include<string>


int distinctSub(string s,string t) {
    int m = s.length();
    int n = t.length();
    if ( m == n && m == 0 ) {
        return 1;
    }
    if (m > n) {
        return 0;
    } 
    int opt = 0;
    int opt1 = 0;
    int retV = 0;
    //match
    if (s[0] == t[0]) {
       opt =  distinctSub (s.substr(1,m-1),t.substr(1,n-1));
    } else {
    //delete
        opt1 = distinctSub  (s,t.substr(1,n-1));
    }
    retV += max (opt,opt1);
    return retV;
}

int main () {
}

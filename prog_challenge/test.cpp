#include<iostream>
#include<algorithm>
#include<string>
using namespace std;



int main () {
    string t = "testdd";
    cout << t << endl;
    //transform(t.begin(),t.end(),t.begin(),::sort);
    sort(t.begin(),t.end());
    cout << t << endl;
}


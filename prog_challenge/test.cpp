#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct CompareString {
    bool operator() (const string &a,const string &b) {
        return (a > b);
    }
};

bool CompareS (const string &a,const string &b) {
    return (a+b > b+a);
}

int main () {

    string a [] = {"3","34","9","5"}; 
    vector<string> av (a,a+sizeof(a)/sizeof(a[0]));
    //sort(av.begin(),av.end(),CompareString);
    sort(av.begin(),av.end(),CompareS);

    for (auto &i:av) {
        cout << i << ",";
    }
    cout << endl;


    //string t = "testdd";
    //cout << t << endl;
    ////transform(t.begin(),t.end(),t.begin(),::sort);
    //sort(t.begin(),t.end());
    //cout << t << endl;

    //int a[] = {3,4,5,6,7,9};
    //int len = sizeof(a)/sizeof(a[0]);
    //sort(a,a+len);

    //for (auto &it:a) {
    //    cout << it << ",";
    //}
    //cout << endl;


    //string resultStr = "abcde";
    //int n = resultStr.length();
    //for (int i=n-1;i>=2;i--) {
    //    for (int start = 0;start<n-i;start++) {
    //        int end = start + i - 1;
    //        //cout << resultStr.substr(start,end-start+1) << endl;
    //        cout << resultStr.substr(start,i-start+1) << endl;
    //    }
    //}


}


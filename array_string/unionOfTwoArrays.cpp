#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Given 2 sorted arrays merge of 2 arrays to give the union
void unionOfArray (vector<int>& a,vector<int>& b) {

    int m = a.size() - 1;
    int n = b.size() - 1;
    stack<int> result;
    
    while (m >= 0 && n >= 0) {
        if (a[m] < b[n]) {
            if (result.empty() || result.top() != b[n]) {
                result.push(b[n]);
            } 
            n--;
        } else if (b[n] < a[m]) {
            if (result.empty() || result.top() != a[m]) {
                result.push(a[m]);
            } 
            m--;
        } else if (b[n] == a[m]) {
            if (result.empty() || result.top() != a[m]) {
                result.push(a[m]);
            }
            n--;
            m--;
        }
    }
    while (m >= 0) {
        if (result.empty() || result.top() != a[m]) {
            result.push(a[m]);
        }
        m--;
    } 
    while (n >= 0) {
        if (result.empty() || result.top() != b[n]) {
            result.push(b[n]);
        }
        n--;
    }
    vector <int> op ;
    while (!result.empty()) {
        cout << result.top() << "," ;
        op.push_back(result.top());
        result.pop();
    }

    cout << endl;

}

int main () {
    int a[] = {1,2,2,4,5,6};
    int b[] = {2,3,5,5,7};
    
    vector<int> av(a,a+sizeof(a)/sizeof(a[0]));
    vector<int> bv(b,b+sizeof(b)/sizeof(b[0]));
    unionOfArray (av,bv);
}

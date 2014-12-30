#include<iostream>
#include<string>
#include<vector>
using namespace std;

void enumAllSubset (string &input,int k,vector<int> &candidate) {
    int n = input.length();
    if ( k == n-1) {
        string tmp = "";
        for (int i=0;i<n;i++)  {
            if (candidate[i]) {
                tmp += input[i];
            }
        }
        cout << tmp << endl;
        return;
    } else {
        k = k+1;
        candidate[k] = 1;
        enumAllSubset (input,k,candidate);
        candidate[k] = 0;
        enumAllSubset (input,k,candidate);
    }

}

int main () {
    string ip = "abc";
    int n = ip.length();
    vector<int> c(n,1);
    enumAllSubset (ip,-1,c);
}

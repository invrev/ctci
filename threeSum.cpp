#include<iostream>
using namespace std;

//O(n^3) algorithm
void isSumof3Array (vector<int>&a,vector<int>&b,vector<int>&c,int sum) {
    int m = a.size();
    int n = b.size();
    int o = c.size();
    int tmpSum = sum;
    for (int i=0;i<m;i++) {
        tmpSum -= a[i];
        for (int j=0;j<n;j++) {
            tmpSum -= b[j];
            for (int k=0;k<o;k++) {
                tmpSum -= c[k];
            }
        }
        if (tmpSum == 0) {
            cout << "found the triplet" << endl;
        } else {
            tmpSum = sum;
        }
    }
}


int main () {

}

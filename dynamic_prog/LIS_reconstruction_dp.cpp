#include<iostream>
#include<vector>
using namespace std;


//It reconstruct the LCS by storing the bestEnd
//Time complexity : O(n^2)
void getLIS(vector<int>& a) {
    int n = a.size();
    vector<int> prev (n,-1);
    vector<int> opt (n,0);
    prev[0] = -1;
    opt[0] = 1;
    int bestEnd = 0;
    int maxLen = 1;
    for (int i=1;i<n;i++) {
        opt[i] = 1;
        prev[i] = -1;
        for (int j= i-1;j>=0;j--)  
        { //Previous elements
            if ((opt[j] + 1 > opt[i]) && (a[j] < a[i]) ) {
               opt[i] = opt[j] + 1;
               prev[i] = j;
            }
        }
        if (opt[i] > maxLen) {
            maxLen = opt[i];
            bestEnd = i;
        }
    }
    cout << "(" <<  maxLen << "," << bestEnd << ")" << endl;
    while (bestEnd != -1) {
        cout << a[bestEnd] << "," ;
        bestEnd = prev[bestEnd];
    }
    cout << endl;
}


int main () {
    int a[] = {9,2,5,3,7,11,8,10,13,6};

    vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
    getLIS(av);
}

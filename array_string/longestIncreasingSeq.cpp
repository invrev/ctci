#include<iostream>
#include<vector>
using namespace std;

//(ex. {1, 4, -1, 2, 6, 7, 1, 4, 2}), 
//    return the biggest sequence of ascending numbers (ex {2, 6, 7}). 
vector<int> getLargestSeq (vector<int>& a) {
    //O(n)
    vector<int> result;
    int n = a.size();
    int maxLen = 0;
    int start = 0;
    int end = 0;
    int j = 0;
    int tmpStart = 0;
    for (int i=1;i<n;i++) {
        //cout << a[i] << ","  << a[j] << endl;
        if (a[i] >= a[j]) {
            if (maxLen < (i-tmpStart) ) {
                maxLen = i-tmpStart;
                start = tmpStart;
                end = i;
            }
        } else {
            tmpStart = i;
        }
        j = i;
    }

    cout << "(" << start << ","  << end << ") = " << maxLen << endl;
    for (int i=start;i<=end;i++) {
        result.push_back(a[i]);
    }
    return result;
}

//optimization : use maxLen instead of end


int main () {
    int a[] = {1, 4, -1, 2, 6, 7, 1, 4, 2};
    vector<int> ip (a,a+sizeof(a)/sizeof(a[0]));
    getLargestSeq (ip);
}

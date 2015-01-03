#include<iostream>
#include<vector>
using namespace std;

//maxmimum number of consecutive 1's


//Given sorted array resturn all ranges

//[0,1,2,4,6,7,8] has ranges 0-2, 4-4, and 6-8.
//compute offset 3 parts index = a[index] , index != a[index]
//Given algoithm in of O(n) however can it be reduced to (log n)
vector<pair<int,int> > createRange (vector<int>& a) {
    int start = 0;
    int end = 0;
    int len = a.size();
    int tmpStart = start;
    vector<pair<int,int> > result;
    for (int i=1;i<len;i++) {
        if (a[i] - a[tmpStart] == 1) {
            end++;
        }else {
           result.push_back (make_pair(a[start],a[end])) ; 
           cout << "(" << a[start] << "," << a[end] << ")" << endl;
           start = tmpStart+1;
           end++;
        }
        tmpStart = i;
    }
    if (start !=0 && end != 0) {
        result.push_back (make_pair(a[start],a[end])) ; 
        cout << "(" << a[start] << "," << a[end] << ")" << endl;
    }
    return result;
}

int main () {

    int a[] = {0,1,2,4,6,7,8};
    vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
    createRange (av);
}


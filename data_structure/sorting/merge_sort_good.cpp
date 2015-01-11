#include<iostream>
#include<vector>
using namespace std;

//Merge sort
void merge(vector<int>& A,vector<int>& left,vector<int>& right) {
    int m = left.size();
    int n = right.size();
    int t = A.size();
    if (t != m+n) {
        return;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n) {
        if (left[i] <= right[j]) {
            A[k++] = left[i++];
        } else {
            A[k++] = right[j++];
        }
    }

    while (i < m) {
        A[k++] = left[i++];
    } 
    while (j < n) {
        A[k++] = right[j++];
    }
}

void mergeSort(vector<int>& A) {
    int n = A.size();
    if (n > 1) {
        vector<int>left(A.begin(),A.begin()+n/2);
        vector<int>right(A.begin()+n/2,A.end());
        mergeSort(left);
        mergeSort(right);
        merge(A,left,right);
    }

}

void printSolution(vector<int>& input) {
    for (int i=0;i<input.size();i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}


void test() {
    int ip[] = {5,4,3,1,8,7};
    vector<int> ipVec(ip,ip+sizeof(ip)/sizeof(ip[0]));
    printSolution(ipVec);
    mergeSort(ipVec);
    printSolution(ipVec);

}

int main () {
    test();
}

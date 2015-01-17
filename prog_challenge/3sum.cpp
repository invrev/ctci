#include<iostream>
#include<vector>
#include<utility>
using namespace std;
//a+b+c = 0

//if array is sorted
struct Triplet {
    int a;
    int b;
    int c;
    Triplet (int x,int y,int z) : 
        a(x),b(y),c(z)
    {

    };
};

vector<Triplet> get3Sum (int a[],int n) {

    vector <Triplet> result;
    //3 elements
    for (int i=0;i<n-2;i++) {
        int tmp = a[i];
        int start = i+1;
        int end = n-1;
        while (start < end) {
            if (tmp + a[start] + a[end] == 0) {
                //get the triplet
                result.push_back(Triplet(i,start,end));
                start++;
                end--;
            } else if (tmp + a[start] + a[end] > 0) {
                end--;
            } else {
                start++;
            }
        }
    }
    return result;
}

vector< pair<int,int> > get2Sum (int a[],int n,int sum) {

    //a[start] + a[end] = sum
    //a[start] + a[end] > sum
    //a[start] + a[end] < sum
    int start = 0;
    int end = n - 1;
    vector<pair <int,int> > result;
    while (start < end) {
        if ( (sum - a[start]) == a[end]) {
            //found the result
            result.push_back( make_pair (start,end) );
            start++;
            end--;
        } else if ( a[end] > (sum - a[start]) ) {
            end--;
        } else {
            start++;
        }
    }
}


int main () {

    int a[] = {};

}

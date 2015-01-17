#include<iostream>
using namespace std;

//(Total choices remaining,Total elements remaining)
//2 subproblem either choose k /pick k 1. (n-1,k-1) 
//or do not choose k/don't pick k      2. (n-1,k)

//4 can choosen from 4 only 1 way 
//0 can be choosen from 4  only 1 way
int nChooseK (int n,int k) {
    if (n == k || k == 0) {
        return 1;
    }
    return ( nChooseK (n-1,k) + nChooseK (n-1,k-1));
}

int main () {
    int result = nChooseK (4,0);
    cout << result << endl;
    result = nChooseK (4,4);
    result = nChooseK (6,4);
    cout << result << endl;
}

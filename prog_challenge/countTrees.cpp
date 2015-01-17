#include<iostream>
using namespace std;


//f(i) = f(j-1) * f (i-j)


int numTrees (int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int sum = 0;
    for (int i=1;i<=n;i++) {
        //due to i-1 need to start from 1
        sum+= numTrees (i-1) * numTrees (n-i);
    }
    return sum;

}

int numTreesDP (int n) {
    vector <int> opt (n+1,0);
    opt[0] = 1;
    opt[1] = 1;
    for (int i=2;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            opt[i] += opt[j-1] * opt[i-j];
        }
    }
    return opt[n];
}




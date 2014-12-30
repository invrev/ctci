#include<iostream>
#include<vector>

//# of ways to climb up to nth staircase
//f(n) = f(n-1) + f(n-2) + f(n-3)
int waysToClimbUp (int n) {
    int noOfWays;
    vector<int> result(n+1,0);
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;
    for (int i=4;i<n;i++) {
       result[i] = result[i-1] + result[i-2] + result[i-3];
    }
    return result[n];
}


int waysToClimbUpR (int n) {
    if (n < 0) {
        return 0;
    } 
    else if (n == 0) {
        return 1;
    }
    else if (n < 3) {
        return n;
    } 
    else {
        return (eaysToClimbUpR (n-1) + eaysToClimbUpR (n-2) 
                + eaysToClimbUpR (n-3));
    }
}



int main () {

}

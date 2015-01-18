#include<iostream>
#include<string>
using namespace std;


//minCut(i,j) = min ( minCut , minCut (i,k) + minCut(k,j) );


int findNumberOfMinCut (string ip) {
    if (isPalindrome(ip)) {
        return 1;
    }
    int minCut = ip.size() - 1;
    for (int k=0;k<m;k++) {  
        minCut = min ( (findNumberOfMinCut (0,k) + findNumberOfMinCut (k,ip.length() - k) ),minCut);
    }
    return minCut;
}


int main () {

}

#include<iostream>
using namespace std;

//If numbers are repeated by more than k times while k != 1
int findMissingElement(int a[],int n) {
    //Idea : store the # of set bits for each position 
    int count[32]  = {0};
    int missingNumber = 0;
    for (int i=0;i<32;i++) {
        for (int j=0;j<n;j++) {
            if ( (a[j] >> i) & 1) {
                count[i]++;
            }
        }
        missingNumber |= ( (count[i] % 3) << i);
    }

    return missingNumber;
}



int main () {

}

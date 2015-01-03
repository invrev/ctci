#include<iostream>
using namespace std;

//count the # of zeros in the factorial

//count the number of 5's in n
int countNumberofZeros (int n) {
    int pair5 =0;
    for (int i=5;i<n;i += 5) {
        int tmp = i;
        while (tmp % 5 == 0) {
            pair5++;
            tmp = tmp/5;
        }
    }
    return pair5;
}

//(log n) with base 5
int countNumberofZeros (int n) {
    int pair5 = 0;
    
    while(n) {
        pair5 += n/5;
        n /= 5;
    
    }
    return pair5;
}

void test (int n) { 
    int result = countNumberofZeros(n);
    cout << "# of zeros in " << n << " = " << result << endl;
}

int main () {
    test(26);
}

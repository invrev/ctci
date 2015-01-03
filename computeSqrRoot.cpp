#include<iostream>
using namespace std;

//Linear search
int getSqrRoot (int number) {
    //1 : number
    for (int i=1;i<number;i++) {
        if (i * i == number) {
            return i;
        }
    }
}

//Binary search
int getSqrRootBin (int number) {

    int start = 1;
    int end = number;
    int result = 0;
    int mid = 0;
    while (start <= end) {      //NOTE : in typical bin search it starts from idx = 0 goes upto n
        mid = start + ( (end - start) / 2 );
        //int tmpResult = mid * mid;
        if ( mid == number/mid ) {  // mid will be never zero and handles perfect square case
            return mid;
        //} else if (tmpResult < number) {
        } else if (mid < number/mid ) {
            start = mid + 1;
            result = mid; //store the last choice for 
            //start++;
        } else {
            end = mid - 1; //Don't store mid in the result as for eg. sqrt(2) = 1 if you store 2 it will be wrong
            //end--;
        }
    }
    //cout << "r1 = " << mid << endl;
    //cout << "r2 = " << result << endl;
    return result;
}

void test (int n) {
    //int result = getSqrRoot (n);
    //cout  << "the sqr root of " << n << " = " << result << endl;

    int result = getSqrRootBin (n);
    cout  << "the sqr root with binary " << n << " = " << result << endl;
}

int main () {
    test(9);
    test(81);
    test(4);
    test(3);
    test(5);
}

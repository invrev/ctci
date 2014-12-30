#include<iostream>
using namespace std;

//25 / 3
//25  , 12 , 6 , 3
//145 9 
//27 : 18 13  11 10
//Division w/o division operation

//27 : get the upper limit 
//9^2 : 81/9

//for eg 27/9
//1.Using the power compute the upper limit (count * number) 9^1 9^2 : (1 to 9)
//2.use this approach 81 : last 9 : start :mid : 27
//int divOperationWithBinSearch (int start,int end) {
//    int count = 0;
//    int start = 0;
//    while (end <= start) {
//        int mid = (start + end) >> 1;
//        if (mid * start ) {
//
//        }
//    }
//
//}

int divOperation (int start,int end) {
    int count = 0;
    //12/2 : 12 => start 2=>end
   
    while (end <= start) {
        start -= end;
        count++;
    }
    return count;
}


void test (int a,int b) {
    int result = divOperation (a,b);
    cout << "(" << a << "/"  << b << ") = " << result << endl;
}

int main () {
    test(12,2);
    test(2,2);
    test(2,12);
}


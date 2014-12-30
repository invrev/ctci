#include<iostream>
using namespace std;


bool isGreyCodeNbrs (int a,int b) {

    //check prev(a) == b or next(a) == b
    if ( b == (a ^ 1)  || b == (a ^ ( (a & -a) << 1)) )  {
        return true;
    } 
    return false;
}

int main () {

}

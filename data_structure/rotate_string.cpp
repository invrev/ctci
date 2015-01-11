#include<iostream>
#include<string>
using namespace std;

//Rotate string by k places 

void reverse (string &ip,int start,int end) {
    while (start < end) {
        swap(ip[start++],ip[end--] );
    }
}

//after0 = abcdefgh
//after1 = abchgfed
//after2 = defghcba

void rotateByKPlaces (string &ip,int k) {
    int end = ip.length();
    reverse(ip,0,k-1); //a^rb
    cout << "after0 = " << ip << endl;
    reverse(ip,k,end-1); //a^rb^r
    cout << "after1 = " << ip << endl;
    reverse(ip,0,end-1); //a^rb^r
    cout << "after2 = " << ip << endl;
}

void test (string ip,int k) {
    cout << "B4 = " << ip << endl;
    rotateByKPlaces (ip,k);
    cout << "after = " << ip << endl;
}

int main () {

    test ("cbadefgh",3);
}


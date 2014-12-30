#include<iostream>
#include<string>
using namespace std;


void permuteString(string& input,int k) {
    int len = input.length();
    if (k == len-1) {
        cout << input << endl;
    } else {
        k = k + 1;
        for (int i=k;i<len;i++) {
            swap(input[i],input[k]); 
            permuteString(input,k);
            swap(input[k],input[i]); 
        }

    }
}

int main () {

    string input = "abc";
    permuteString(input,-1);
}

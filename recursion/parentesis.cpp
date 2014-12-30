#include<iostream>
#include<string>
using namespace std;


void enumParenthesis (string& op,int n,int left,int right) {
    if (left+right == 2*n) {
        cout << op << endl;
        return;
    } else {
        //k = k+1;
        if (left < n) {
            op += '(';
            //NEVER user left++ or ++left : it increases left by value only at the level
            enumParenthesis (op,n,left+1,right);
            op.pop_back();
        }
        if (left > right) {
            op += ')';
            enumParenthesis (op,n,left,right+1);
            op.pop_back();
        }
    }
}

int main () {
    string op = "";
    int left = 0;
    int right = 0;
    int n = 3;
    enumParenthesis (op,n,left,right);
}


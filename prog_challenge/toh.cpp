#include<iostream>
#include<vector>
using namespace std;


//2 1
//2 1

void moveTOH (int n,int src,int dest,int spare) {
    if (n == 0) {
        cout << "moving from src to dest " << endl;
        return;
    } 
    moveTOH (n-1,src,spare,dest);
    cout << "move n from src to dest" << endl;
    moveTOH (n-1,spare,dest,src);
}

int main () {

}


#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;


//Implement Min Stack should return the min in O(1) 
//1,2,3,4,5
//1
//5
//4
//3   1
//2   2
//11 11

struct MinStack {
    stack<int> minStack;
    stack<int> nStack;
    //int sSize;
    //MinStack (int sSize) 
    //:sSize(sSize),minStack(size),nStack(size)
    MinStack () 
    {

    };
};

int cPop(MinStack &s) {
    if (s.minStack.empty()) {
        return INT_MIN;
    } 
    int retInt = s.nStack.top();
    if (s.nStack.top() == s.minStack.top()) {
        s.minStack.pop();
    }
    s.nStack.pop();
    cout << "popped element " << retInt << endl;
    return  retInt;
}

void cPush(MinStack& s,int num) {
    s.nStack.push(num);
    //Need to check wheather stack is empty
    if ( s.minStack.empty() || num <= s.minStack.top() ) {
        s.minStack.push(num);
    }
}

int min (MinStack &s) {
    if (s.minStack.empty()) {
        return INT_MIN;
    } 
    int m = s.minStack.top();
    cout << "min element " << m << endl;
    return m;
}



int main () {

    //Using extra stack we can solve the problem

    MinStack m;
    cPush(m,11); 
    cPush(m,12); 
    cPush(m,1); 
    cPush(m,1); 
    cPop (m);
    min(m); 
    cPop (m); 
    min(m); 
    cPop (m); 
    min(m); 
    cPop (m); 


}

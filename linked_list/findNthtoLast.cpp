#include<iostream>

struct LLNode {
    int val;
    LLNode *next;
};

int FindNthToLast (LLNode *head,int n) {
    if (head == 0) {
        return INT_MIN;
    } else {
    
        LLNode *first = head;
        LLNode *second = head;
        while (first &&  (n != 0) ) {
            first = first->next;
            n--;
        }
        if (n != 0) {
            return INT_MIN;
        } else {
            while (first->next && second) {
                second = second->next;
                first = first->next;
            }
            if (second) {
                return second->val;
            }
        }
    }

}

int main () {

}

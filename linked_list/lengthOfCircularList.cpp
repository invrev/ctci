#include<iostream>
using namespace std;

struct ListNode {
    int val ;
    ListNode *next;
    ListNode (int data) : 
        val (data),next(NULL)
    {

    };
};

//loop in the linked list
//If there is circular loop in the linked list then it can be computed  with finding the 
//start node of the circular linked list

int findLengthOfCircularList (ListNode *head) {

    ListNode *curr = head;
    ListNode *nextN = curr->next;
    int len = 0;
    while (curr != nextN) {
        nextN = nextN->next;
        len++;
    }

    cout << "the length of circular linked list "  << len;

}


//Once the slow pointer gets in the cycle, it takes at most one round for the fast pointer to catch up to the slow pointer because the fast pointer is twice as fast. 
//It is certainly true that the program can keep running for a long time, but that only depends on how long the loop is.
//Even in the case when there's no loop, the program can still run for a long time.

bool isLoopInLinkedList (ListNode *head) {

    if (!head || !head->next) {
        return false;
    }
    ListNode *step2 = head->next;
    ListNode *step1 = head;

    while (step1 != NULL || step2 != NULL) {

        if (step1 == step2) {
            cout << "found loop" << endl ;
            return true;
        }
        step1 = step1->next;
        step2 = step2->next->next;

    }

    cout << "NO loop" << endl ;
    return false;

}




int main () {

    ListNode *head = new ListNode (1);
    head->next = new ListNode (2);
    head->next->next = new ListNode (3);
    head->next->next->next = new ListNode (4);
    head->next->next->next->next = new ListNode (5);

    ListNode *tmp = head->next->next;
    head->next->next->next->next->next = tmp;

    isLoopInLinkedList(head);

}


#include<iostream>
#include<unordered_map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : 
        val(x),next(NULL)
    {

    };
};



ListNode *partition(ListNode *head, int x) {
    ListNode *sentiHead = new ListNode(-1);
    ListNode* dummyHead = sentiHead;
    ListNode *sentiTail = new ListNode(-1);
    ListNode* dummyTail = sentiTail ;
    
    while (head) {
        if (head->val < x) {
            dummyHead->next = head;
            dummyHead = dummyHead->next;
        } else {
            dummyTail->next = head;
            dummyTail = dummyTail->next;
        }
        head = head->next;
    }
    dummyTail->next = NULL;
    dummyHead->next = sentiTail->next;
    return sentiHead->next;
}

int main () {
    
}


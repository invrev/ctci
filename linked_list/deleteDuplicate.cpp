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


//Keep only one copy of duplicate node
ListNode *deleteDuplicates(ListNode *head) {

    if (!head) {
        return NULL;
    }
    ListNode *curr = head;
    while (curr->next != 0) {
        if (curr->val == curr->next->val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

//Keep only one copy of duplicate node
ListNode *deleteDuplicatesI_simple(ListNode *head) {
    
    ListNode *sentNode = new ListNode(-1);
    sentNode->next = head;
    ListNode *prev = sentNode;
    ListNode *curr = head;
    while (prev) {
        while (curr != NULL && curr->next != NULL && curr->val == curr->next->val) {
            curr = curr->next;
        }
        prev->next = curr;
        prev = curr;
        if (curr) {
            curr = curr->next;
        }
    }
    return sentNode->next;;
}

//Wipe out the all duplicate nodes 
ListNode *deleteDuplicatesII(ListNode *head) {
    
    ListNode *sentNode = new ListNode(-1);
    sentNode->next = head;
    ListNode *prev = sentNode;
    ListNode *curr = head;
    
    while (prev) {
        while (curr != NULL && curr->next != NULL && curr->val == curr->next->val) {
            //To Remove the node completely 
            while(curr->next != NULL && curr->next->val == curr->val) {
                   curr = curr->next;
            }
            curr = curr->next;
        }
        prev->next = curr;
        prev = curr;
        if (curr) {
            curr = curr->next;
        }
    }
    return sentNode->next;;
}


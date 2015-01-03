
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


//swap the node pair
ListNode* do_swap (ListNode *first,ListNode *second) {
    first->next = second->next;
    second->next = first;
    return second;

}

//W/o using the prev pointer only using the one pointer
ListNode *swapPairs_simple(ListNode *head) {
    ListNode *sentiNode = new ListNode (-1);
    sentiNode->next = head;
    ListNode *curr = sentiNode;
    while (curr->next && curr->next->next) {
        curr->next = do_swap ( curr->next,curr->next->next);
        curr = curr->next->next;
    }
    return sentiNode->next;
}

ListNode *swapPairs(ListNode *head) {
    ListNode *sentiNode = new ListNode (-1);
    sentiNode->next = head;
    ListNode *prev = sentiNode;
    ListNode *curr = head;
    while (prev->next && prev->next->next) {
        prev->next = do_swap ( prev->next,curr->next);
        curr = curr->next;
        prev = prev->next->next;
    }
    return sentiNode->next;
}


int main () {

}

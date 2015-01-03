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


//Merge 2 sorted lists
ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
    ListNode *sentiNode = new ListNode(-1);
    ListNode *tmpHead = sentiNode;
    while (head1 && head2) {
        if (head1->val < head2->val) {
            tmpHead->next = head1;
            tmpHead = tmpHead->next;
            head1 = head1->next;
        } else {
            tmpHead->next = head2;
            tmpHead = tmpHead->next;
            head2 = head2->next;
        }
    }
    if (head2) {
        head1 = head2;
    }
    while (head1) {
        tmpHead->next = head1;
        tmpHead = tmpHead->next;
        head1= head1->next;
    }
    return (sentiNode->next);
}

int main () {

}

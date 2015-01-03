#include<iostream>
#include<unordered_map>
using namespace std;

//Add two numbers using the linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : 
        val(x),next(NULL)
    {

    };
};

//(2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
//this is straight addition
//Idea is to append the nodes to the list so created sentinelNode 
//Use of sentinel node elimiates think of condition where l1 and l2 is null
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* resultNodeHead = new ListNode(0);
    ListNode* resultNode = resultNodeHead;
    int carry = 0;
    while (l1 && l2) {
        int result = l1->val + l2->val + carry;
        carry = result/10;
        result = result % 10;
        resultNode->next = new ListNode(result);
        resultNode = resultNode->next;
        l1 = l1->next;
        l2 = l2->next; 
    }
    //Swap the nodes if other is empty
    if (l2) {
        l1 = l2;
    }
    while (l1) {
        int result = l1->val + carry;
        l1 = l1->next;
        carry = result/10;
        result = result % 10;
        resultNode->next = new ListNode(result);
        resultNode = resultNode->next;
    }
    if (carry == 1) {
        resultNode->next = new ListNode(carry);
    }
    return resultNodeHead->next;
}

int main () {

}

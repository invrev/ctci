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

//get the intersection
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //We assume len(headA) < len(head2)
    int lenA = 0;
    int lenB = 0;
    ListNode *cheadA = headA;
    ListNode *cheadB = headB;
    while (cheadA) {
        lenA += 1;
        cheadA = cheadA->next;
    } 
    while (cheadB) {
        lenB += 1;
        cheadB = cheadB->next;
    }

    if (lenA > lenB) {
        ListNode *tmp = headA;
        headA = headB;
        headB = tmp;
    }
    int offset = max(lenA,lenB) - min (lenA,lenB);
    cheadA = headA;
    cheadB = headB;
    while (offset != 0 ) {
        cheadB = cheadB->next;
        offset -= 1;
    }
    while (cheadA && cheadB) {
        if (cheadA == cheadB) {
            return (cheadA);
        }
        cheadA = cheadA->next;
        cheadB = cheadB->next;
    }
    return NULL;
}

int main () {

}


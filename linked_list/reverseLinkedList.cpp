
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


//Reverse linked list 
//1->2->3->4->5
//1<-2<-3<-4<-5

ListNode* reverseLinkedList(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *curr = head;
    //ListNode *next_p = head->next;
    ListNode *next_p = NULL;
    while (curr) {
        next_p = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_p;
    }
    return prev;
}

//think in top-down order start from the head
//Tail recursion
ListNode* reverseLinkedHelper(ListNode *curr,ListNode *prev) {
    if (curr == NULL) {
        return prev;
    } else {
        ListNode *next_p = curr->next;
        curr->next = prev;
        return reverseLinkedHelper(next_p,curr);
    }
}

ListNode* reverseLinkedRec(ListNode *head) {
    return ( reverseLinkedHelper(head,NULL) ) ;
}

void printList (ListNode *head) {
    while (head)  {
        cout << head->val << " " ;
        head = head->next;
    }
    cout << endl;
}


int main () {
   
    ListNode *head = new ListNode(1); 
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    //removeNthFromEnd (head,2);
    //int a[] = {1,0,2,2,0,2,0,0};
    //int len = sizeof(a)/sizeof(a[0]);
    //parition (a,a[1],len);
    printList(head);
    //ListNode *hList = reverseLinkedList (head);
    ListNode *h1List = reverseLinkedRec (head);
    printList(h1List);

}






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

struct RandomListNode  {
    int label;
    RandomListNode *next;
    RandomListNode *random;
    RandomListNode (int x) : 
        label(x),next(NULL),random(NULL) 
    {

    };
};


bool hasCycle (ListNode *head) {
    //use of tortoise and hare
    return true;
}





ListNode* findMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


//1,0,2,2,0,2,0,0
int parition (int a[],int k,int size) {
    int q = -1;
    int i = 0;
    while (i < size) {
        if (a[i] <= k) {
            q += 1;
            swap (a[i],a[q]);
        }
         i++;
    }
    cout << endl;
    for (int i=0;i<size;i++) {
        cout << a[i] << " ";
    }
    cout << endl;

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





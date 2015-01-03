
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




//1->2->3->4->5, and n = 2.
//1->2->3->5
ListNode *removeNthFromEnd(ListNode *head, int n) {
   if (!head)  {
       return NULL;
   }
   int start = 0;
   ListNode *sentinelNode = new ListNode(-1);
   sentinelNode->next = head;
   ListNode *first = sentinelNode;
   ListNode *second = sentinelNode;
   while (start < n) {
       first = first->next;
       start += 1;
   }

   cout << "first " << first->val << endl;
   //while (first != NULL)  W/O sentinel node
   while (first->next != NULL) {
       first = first->next;
       second = second->next;
   }
   cout << "second " << second->val << endl;
   //second->val = second->next->val;
   second->next = second->next->next;

   return sentinelNode->next;
}

int main () {

}

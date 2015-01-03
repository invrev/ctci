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



void divideList(ListNode *head,ListNode **firstH,ListNode **secondH) {
    ListNode *slow = head;
    ListNode *fast = head;    
    ListNode *prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    firstH = &head;
    secondH = &slow;
}

int main () {

}

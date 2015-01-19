#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int data) :
        val(data),next(NULL)
    {

    };
};


//1  3  3  4 5
//a->b->c->d->e  m = 3 ,n = 4

//1.reverse
//a->b  c<-d->e

//2.merge
//a->b  c<-d ----->e

//a->b->d->c->e

ListNode * reverseListToandFrom (ListNode *head,int m,int n) {

    ListNode *senti = new ListNode(-1);
    senti->next = head; 
    head = senti;
    //if (m <= n ) {
    //    return head;
    //}
    int step = m - n; 
    ListNode *current = head;
    ListNode *prev = head;
    ListNode *nextP = NULL;
    while (m != 0) {
        prev = current;
        current = current->next;
        m--;
        n--;
    }
    if (step >= 1) {
        nextP = current->next;
        while ( nextP != NULL && n != 0) {
            ListNode *tmpNode = nextP->next;
            nextP->next = current; 
            current = nextP; //d
            nextP = tmpNode;  //e
            n--;
        }
        ListNode *tmpNode = prev->next;
        prev->next = current;
        tmpNode->next = nextP;
    }
    senti = head;
    head = head->next; 
    delete senti; 
    return head;
}

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

//Use of unordered_map
RandomListNode *copyRandomList(RandomListNode *head) {
    //takes care of condition (!head) 
    RandomListNode *curr = head;
    RandomListNode* sentinelNode = new RandomListNode(-1);
    RandomListNode* headNode = sentinelNode;
    unordered_map <RandomListNode*,RandomListNode*> rMap;
    while (curr) {
        headNode->next = new RandomListNode(curr->label);
        headNode = headNode->next;
        rMap[curr] = headNode;
        curr = curr->next;
    }
    //copy the random pointers
    curr = head;
    while (curr) {
        //curr->random checks wheather it is null or not in order to avoid null pointer exception in find
        if ( curr->random && rMap.find(curr) != rMap.end() && rMap.find(curr->random) != rMap.end() ) {
            RandomListNode* headR = rMap[curr];
            headR->random = rMap[curr->random];
        }
        curr = curr->next;
    }
    return (sentinelNode->next);
}


int main () {

}


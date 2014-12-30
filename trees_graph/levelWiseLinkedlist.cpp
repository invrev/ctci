#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct LLNode {
    int val;
    LLNode *next;
    LLNode (int aVal)  : 
        val(aVal),next(NULL)
    {
    };
};

struct BTNode {
    int val;
    BTNode *left;
    BTNode *right;
    BTNode (int aVal) : 
        val(aVal),left(NULL),right(NULL)
    {

    };
};

void createLevelWiseTree(BTNode *root) {
    queue <BTNode *> visitedQ;
    visitedQ.push(root);
    int nextVisited = 0; 
    int currentVisited = 1; 
    vector<LLNode *> llV;
    LLNode *head = new LLNode(-1);
    while (!visitedQ.empty()) {
        BTNode *tmpNode = visitedQ.front();
        currentVisited--;
        LLNode *ltmpNode = new LLNode(tmpNode->val);
        ltmpNode->next = head;
        head = ltmpNode;
        if (tmpNode->left) {
            visitedQ.push(tmpNode->left);
            nextVisited++;
        }
        if (tmpNode->right) {
            visitedQ.push(tmpNode->right);
            nextVisited++;
        }
        visitedQ.pop();
        if (currentVisited == 0) {
            llV.push_back(head);
            head = NULL;
            head = new LLNode(-1);
            currentVisited = nextVisited;
            nextVisited = 0;
        }
    }
}

int main () {

}

#include<iostream>

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode (int aVal) : 
        val(aVal),left(NULL),right(NULL)
    {

    };
};


//     3
//   /  \
//  9   20
// /   /  \
// 90  15   7

//DLR :  after D it changes to if
void iterativePreorder (TreeNode *root) {
    if (!root) {
        return;
    }
    TreeNode *tmpNode = root;
    stack<TreeNode *> tStack;
    if (tmpNode) {
        tStack.push(tmpNode);
    }
    while (!tmpNode || !tStack.empty()  ) {
        //if (tmpNode)  {
        //    tStack.push(tmpNode);
        //}
        tmpNode = tStack.top();
        tStack.pop();
        //NOTE : on the stack we need to put right and then left in order to visit the right node
        //visit right
        if (tmpNode->right) {
            tmpNode = tmpNode->right;
            tStack.push(tmpNode);
        }
        //visit left
        if (tmpNode->left) {
            tmpNode = tmpNode->left;
            tStack.push(tmpNode);
        }

    
    }


}


int main () {

}

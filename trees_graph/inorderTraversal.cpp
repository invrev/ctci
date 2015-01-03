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

//  LDR
//   |_LDR

void traverseInorder (TreeNode *root) {
    TreeNode *tmpNode = root;
    stack<TreeNode *> tStack;
    while (!tmpNode || tStack.empty()) {
       while (tmpNode) {
           tStack.push(tmpNode);
           tmpNode = tmpNode->left;
       }
       tmpNode = tStack.top();
       cout << tmpNode->val << " ";
       if (tmpNode->right) {
           tmpNode = tmpNode->right;
           tStack.push(tmpNode);
       }
    }
}


int main () {

}

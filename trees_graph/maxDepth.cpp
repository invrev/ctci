#include<iostream>


struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode (int data) : 
        val(data),left(NULL),right(NULL)
    {

    };

}

//Do the preorder traversal
int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if (leftDepth == 0 && rightDepth == 0) {  //Leaf Node
        return 1;
    } else if (leftDepth == 0)  {
          return 1 + rightDepth;
    } else  if (rightDepth == 0) {
        return 1 + leftDepth;
    } else {
        return 1 + max(leftDepth, rightDepth);
    }
}


int main () {

}

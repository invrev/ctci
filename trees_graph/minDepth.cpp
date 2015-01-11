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

//Do the preorder traversal ()
//NOTE : min dept

//1.//          12

//2.//            12
//  //       8         40
//  //   4          31 
//  //2       

int minDepth () {
  if (root == NULL) {
      return 0;
  }
  int leftDepth = minDepth(root->left);
  int rightDepth = minDepth(root->right);
  if (leftDepth == 0 && rightDepth == 0) {  //Leaf Node
      return 1;
  } else if (leftDepth == 0)  {
        return 1 + rightDepth ;
  } else  if (rightDepth == 0) {
      return 1 + leftDepth;
  } else {
      return 1 + min(leftDepth, rightDepth);
  }
}

int main () {

}

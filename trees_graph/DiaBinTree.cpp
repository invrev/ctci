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

//Preoder traversal LRD

//* the diameter of T’s left subtree
//* the diameter of T’s right subtree
//* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)
//O(n^2)
int maxDiam (TreeNode *root) {
    if (!root) {
        return root;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    int leftDiam = 0;
    int rightDiam = 0;

    //because of height it tunrs out to be O(n^2)
    leftHeight = height(root->left);
    rightHeight = height(root->right);

    leftDiam = maxDiam (root->left);
    rightDiam = maxDiam (root->right);

    return ( max (max (leftDiam,rightDim) ,1 +leftHeight + rightHeight ) );
}


//O(n) initialize height = 0
int optMaxDia (TreeNode *root,int &height) {
    
    if (root == NULL) {
        height = 0;
        return 0;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    int leftDia = 0;
    int rightDia = 0;
    leftDia = optMaxDia(root->left);
    rightDia  = optMaxDia(root->right);
    height = max(leftHeight,rightHeight) + 1;
    return (leftHeight + rightHeight + 1,max(leftDia,rightDia) );
}

int height (TreeNode *root) {
    if (root == NULL) {
        return 0;
    } 
    return (1 + max ( height (root->left), height(root->right) );
}




int main () {

}

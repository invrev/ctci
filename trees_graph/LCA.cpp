
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int aVal) : 
        val(aVal),left(NULL),right(NULL)
    {

    };
};

//call with bottomUptravesal (root,NULL)
TreeNode* bottomUptravesal (TreeNode *root,TreeNode *parent) {
    if (root == NULL) {
        return root;
    } else {
        TreeNode *tmp = bottomUptravesal (root->left,root);
        if (parent == NULL) {
            root->left = parent;
        } else {
            root->left = parent->right;
        }
        root->right = parent;
        return root;
    }
}

//            12
//       8            40
//   4       10   30       60
//2       9          31 

//LCA(2,9) = 4
//LCA(8,40) = 12


//In case of BST : 
//we can find LCA by comparing the values
//as for LCA the condition is root->left < root > root->right
//then root is LCA

//In case of generic binary tree (do preorder traversal)
//

//Bottomup approach
TreeNode *bottomLCA (TreeNode *root,TreeNode *l,TreeNode* r) {
    if (!root) {
        return root;
    } else {
        if (l == root || r == root) {
            return root;   // at n+1 level (get child)
        }
        //traverse bottom up
        TreeNode *tmpL = bottomLCA (root->left,l,r);  //at nth level (have parent)
        TreeNode *tmpR = bottomLCA (root->right,l,r); //at nth level
        if (tmpL  & tmpR) {
            return root;
        } else if ( tmpL == NULL) {
            return tmpR;
        } else {
            return tmpL;
        }
    }
}

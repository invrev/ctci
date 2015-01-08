
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

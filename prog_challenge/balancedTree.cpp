#include<iostream>
using namespace std;

struct BTNode  {
    BTNode *left;
    BTNode *right;
    int val;
    BTNode (int data) : 
        val(data),left(NULL),right(NULL)
    {

    };
};

BTNode* createBST (BTNode *root,int val) {
    if (root == NULL) {
        root = new BTNode (val);
    } else if (val > root->val) {
       root->right = createBST(root->right,val);
    }else if (val < root->val) {
       root->left = createBST (root->left,val);
    }
    return root;
}

BTNode* createBalancedBST (BTNode *root,int a[],int start,int end) {
    
    if (start < end) {
        int mid = start + (end - start) /2;
        if (!root) {
            root = new BTNode (a[mid];
        }
        root->left = createBalancedBST (root->left,a,start,mid-1);
        root->right = createBalancedBST (root->right,a,mid+1,end);
        return root;
    }
    return NULL;
}

void main () {

}





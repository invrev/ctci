#include<iostream>
using namespace std;

struct BTNode  {
    int val;
    BTNode *left;
    BTNode *right;
    BTNode (int aVal) : 
        val(aVal),left(NULL),right(NULL)
    {

    };
};

BTNode* createBalancedTree (int input[],int start,int end,BTNode *root) {
    if (start < end) {
        int mid = (start + end) / 2;
        root = new BTNode (input[mid]);
        root->left = createBalancedTree (input,start,mid-1,root);
        root->right = createBalancedTree (input,mid+1,end,root);
        return root;
    }
}

void createBalancedTree (int input[],int start,int end,BTNode *root) {
    if (start < end) {
        mid = (start + end) / 2;
        root = new BTNode (input[mid]);
        createBalancedTree (input,start,mid-1,root->left);
        createBalancedTree (input,mid+1,end,root->right);
    }
}

int main () {

}

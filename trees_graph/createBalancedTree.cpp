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

void createBalancedTree (int input[],int n,BTNode *root) {
    int start = 0;
    if (start < n) {
        mid = (start + n) / 2;
        root = new BTNode (input[mid]);
        createBalancedTree (input,mid-1,root->left);
        createBalancedTree (input,mid+1,root->right);
    }
}

int main () {

}

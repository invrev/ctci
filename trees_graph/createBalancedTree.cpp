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

// {1,2,3,4,5,6,7,8}


//1.find mid ,
//2.create root node
//3.root->left = (start,mid-1)
//4.root->right =  (mid+1,end)

//         4 
// {1,2,3}   {5,6,7,8}

//         4 
//     2      {5,6,7,8}
// {1}   {3}  


//         4 
//     2         6
// {1}   {3} {5}   {7,8}

//

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

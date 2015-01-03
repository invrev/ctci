#include<iostream>
using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode (int aVal) : 
        val(aVal),left(NULL),right(NULL)
    {

    };
};

void preOrderTraversal (TreeNode *root) {
    if (root) {
        cout << root->val << "," ;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    } else {
        cout << endl;
        return;
    }
}

//
//     root                        root
//     /  \            ->            \
//  left  right                      left
//                                     \
//                                    right
//
//Preorder : needs to keep track of only right childs as parent gets visited before left and right children
void flattenTree (TreeNode *root) {
    while (root) {
        TreeNode *tmp = root->right;
        root->right = root->left; //Add left subtree to root->right
        root->left = NULL;
        TreeNode *curr = root;  //keep the root in curr
        while (curr->right) {       //traverse the tree down to right untill no right child
            curr = curr->right;     
        }
        curr->right = tmp;      //Add stored right child to curr->right

        root = root->right; //Move forward
    }

}

TreeNode* flattenTreeNodeRec (TreeNode *root) {
   if (!root) {
       return root;  
   }
   //Save the right subtree
   TreeNode rtree = root->right;  

   if (root->left != NULL) {  
     root->right = root->left;  
     root->left = NULL;  
     root = flatten(root->right);  
   }  
   if (rtree != NULL) {  
     root->right = rtree;  
     root = flatten(root->right);  
   }  
   return root;  
}



//        1
//    2       5
// 3     4       6

int main () {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    TreeNode *tmp = NULL;
    flattenTreeNodeRec (root,tmp);
}

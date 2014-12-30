#include<iostream>


//             11
//        7          20
//    4      9    12    21
// 3       8                        inorder(7) : 8

struct BTNode {
    int data;
    BTNode *left;
    BTNode *right;
    BTNode *parent;
    BTNode (int aVal) : data(aVal),left(NULL),right(NULL),parent(NULL) 
    {

    };
};

BTNode* findInorderSucc (BTNode *node) {
    

    int currentVal = node->data;
    if (node->right != NULL) {
        node = node->right;
        if ( node != NULL && node->left != NULL) {
            node = node->left;
        }
        return node;
    } else {

        BTNode *tmpNode = node;
        node = node->parent;
        while (node != NULL && node->left != tmpNode) {
            tmpNode = node;
            node = node->parent;
        }
        return node;

        //while (node) {
        //    node = node->parent;
        //    if (node->data > currentVal) {
        //        return node;
        //    }
        //}
    }
}


int main () {

}

#include<iostream>
using namespace std;

//check wheather binary tree is balanced or not
//        a 
//          b
//            c
//     a
//   c   b
// s
int heightHelper (BTNode *node,bool &result) {
    if (!node) {
        return 0;
    }
    int lh = heightHelper(node->left);
    int rh =  heightHelper(node->right);
    //ASA find the imbalncing return from SF
    if ( abs (lh - rh) > 1) {
        result = false;
        return -1;
    }
    if (lh == 0 && rh == 0) {
        return 1;
    } 
    if (lh == 0) {
        return (1 + rh);
    }
    if (rh == 0) {
        return (1+lh);
    }
    return 1 + max(lh,rh);
    
}    

bool isValidBalnce(BTNode *root) {

    if ( !root || root->left == NULL && root->right == NULL) {
        return true;
    }
    
    bool result = true; 
    int tmp = heightHelper (root,result);
    return result;
}


//WROG implementation
int heightHelper (BTNode *node) {
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    if (node->left == NULL) {
        return ( 1+heightHelper (node->right) ) ;
    }
    if (node->right == NULL) {
        return ( 1+heightHelper (node->left) ) ;
    }
    return (1 + max( heightHelper(node->left),heightHelper(node->right) ) );
} 

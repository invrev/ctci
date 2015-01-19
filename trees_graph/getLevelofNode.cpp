#include<iostream>
using namespace std;

struct BTNode {
};

//Find the level of the node from binary tree w.r.t. root


//return 0 means no node found

int getLevelOfNode (BTNode *root,BTNode *node,int level) {
    
    if (!root) {
        return 0;
    }
    
    if (root == node) {
        return level;
    }
    
    int retL = getLevelNode (root,node->left,level+1);
    if (retL != 0) {
        return retL;
    }
    retL = getLevelNode (root,node->right,level+1);
    return retL;
}


int level = getLevelOfNode (root,node,1);

#include<iostream>


struct BTNode {
    BTNode *left;
    BTNode *right;
    int val;
};

//Print the path from ROOT to leat with a backtracking 
void getSumPath (BTNode* root,int sum,vector<BTNode*>& op,vector<vector<BTNode*> >&result) {

    if (!root) {
        return;
    }
    else if (sum == root->val && root->left == NULL 
            && root->right == NULL ) {
        op.push_back(root);
        result.push(op);
        op.pop_back(root);
        return;
    } else {
        int val = root->data;
        op.push_back(root);
        getSumPath (root->left,sum-val,op,result);
        getSumPath (root->right,sum-val,op,result);
        op.pop_back();
    }
}


//To check wheather there is path from Root to leaf that has given sum
bool isSumPathFromRToL (BTNode* root,int sum) {

    if (!root) {
        return true;
    }else if (sum == root->val && root->left == NULL 
            && root->right == NULL ) {
        return true;
    } else {
        int val = root->data;
        return (isSumPathFromRToL (root->left,sum-val,op,result) || isSumPathFromRToL (root->right,sum-val,op,result) );
    }
}

int main () {

}

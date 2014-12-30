#include<iostream>
#include<vector>
using namespace std;

struct BTNode {
    int val;
    BTNode *left;
    BTNode *right;
    BTNode (int aVal) : 
        val(aVal),left(NULL),right(NULL)
    {

    };
};


//Compute the path between 
void getPath (BTNode *root,BTNode *first,BTNode *second,vector<BTNode *>&result,vector<vector<BTNode*> >&op) {
    if  (!root) {
        return;
    } else if ( root == first || root == second ) {
        result.push_back (root);
        op.push_back(result);
        result.pop_back();
        return;
    } else {
        result.push_back(root);
        getPath (root->left,first,second,result,op);
        getPath (root->right,first,second,result,op);
        result.pop_back();
    }
}


int main() {
    vector<BTNode *> result;
    vector<vector<BTNode *> > op;
    
    BTNode *root = new BTNode(2);
    root->left = new BTNode(7);
    root->left->left = new BTNode(22);
    root->left->right = new BTNode(6);
    root->left->right->left = new BTNode(5);
    root->left->right->right = new BTNode(11);
    root->right  =  new BTNode(5);
    root->right->right  =  new BTNode(9);
    root->right->right->left  =  new BTNode(4);

    BTNode *first = root->left->left; 
    BTNode *second = root->right->right; 
    getPath (root,first,second,result,op);
    
    int l = op.size();
    vector <BTNode *> firstPath = op[0];
    vector <BTNode *> secondPath = op[1];
    int m = firstPath.size();
    int n = secondPath.size();
    int len = 0;
    int i = 0;
    int j = 0;
    while ( i < m && j < n) {
        if (firstPath[i++] != secondPath[j++] ) {
            len += 2;
        }
    }
    cout <<  "the path len = " << len << endl;
    //for (int i=0;i<l;i++) {
    //    vector<BTNode *> tmpL = op[i];
    //    int t = tmpL.size();
    //    for (int j=0;j<t;j++) {
    //        cout << tmpL[j]->val << "," ;
    //    } 
    //    cout << endl;
    //}
    
}

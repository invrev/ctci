#include<iostream>
using namespace std;

struct BTNode {
    BTNode *left;
    BTNode *right;
    int val;
    BTNode (int val) : 
        val(val),left(NULL),right(NULL)
    {

    };
};


void preorder (BTNode *t) {
    if (!t) {
        return;
    }
    cout << t->val << ",";
    preorder (t->left);
    preorder (t->right);
    
}


void mirrorImageHelper (BTNode *l,BTNode *r) {
    if (!left && !right) {
        return;
    }
    if (!l) {
       l = r;
    } if (!r) {
        r = l;
    } else if (l != NULL && r!= NULL) {
         BTNode *tmp = l;
         l = r;
         r= tmp;
         mirrorImageHelper (l->left,r->right);
    }
}

void mirrorImage (BTNode *root) {
    if (!root) {
        return;
    }
    mirrorImage(root->left);
    mirrorImage (root->right);    
    BTNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

}





int main () {
   BTNode *root = new BTNode(1);
   root->left = new BTNode(2);
   root->right = new BTNode(3);
   preorder(root);
   cout << endl;
   mirrorImage (root);
   
   preorder(root);
   cout << endl;

}

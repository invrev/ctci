#include<iostream>
using namespace std;


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


BTNode *findLeftMostNode (BTNode *t) {
    while (t->left != NULL) {
        t = t->left;
    }
    return t;
}



BTNode* inOrderSuccessor(BTNode *root, BTNode* target,BTNode *parent) {
    if (root == NULL) {
        return root;
    }
    if (root == target)  {
        if (root->right) {
            return (findLeftMostNode (root->right) );
        } else {

            return parent;
        }
    } else {
    
        //return ( inOrderSuccessor (root->left,target,root) ) ; core dump
        BTNode *left = inOrderSuccessor (root->left,target,root);
        cout << "left = " << left << ",root" << root << endl;
        if (left) {
            cout << "[left = " << left << ",root" << root << endl;
            return left;
        }
        cout << "parent= " << parent << endl;
        return (inOrderSuccessor (root->right,target,parent)  );
    }
    
}

//            17
//       2            30 
//   1       3      25   35
//13       20  9       

int main () {


    BTNode *root = new  BTNode (17);
    root->left = new  BTNode (2);
    root->left->right = new  BTNode (3);
    root->left->right->right = new  BTNode (9);
    root->left->right->left = new  BTNode (20);
    root->left->left = new  BTNode (1);
    root->left->left->left = new  BTNode (13);
    root->right = new  BTNode (30);
    root->right->right = new  BTNode (35);
    root->right->left = new  BTNode (25);

    BTNode *target = root->left->right->right;
    BTNode *target1 = root->left->left->left;
    BTNode* target2 = root->right;
    BTNode* target3 = root->left->right->right;
    bool indicator = false;

    //BTNode *t1 = inOrderSuccessor (root,target1,NULL);
    BTNode *t1 = inOrderSuccessor (root,target3,NULL);

    cout << t1->data << endl;

}

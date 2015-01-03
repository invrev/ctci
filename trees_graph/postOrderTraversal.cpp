#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int aVal) : 
        val(aVal),left(NULL),right(NULL)
    {

    };
};


//             10
//        8          20
//    4      9    12    21
// 3

//LRD 
void postOrderTraversalI (TreeNode *root) {
        stack<TreeNode *> visitS;
        TreeNode *curr = root;
        TreeNode *pre = NULL;
        while (curr || !visitS.empty() ) {
            while (curr) {
                visitS.push(curr);
                curr = curr->left;
            }
            curr = visitS.top();
            if (curr->right && pre != curr->right) { //9 is stored in pre so while 8 poped out just go to else part
                curr = curr->right;  //# see the case 8,9
            } else {
                pre = curr;
                visits.pop();
                cout << curr->val << " ";
                curr = NULL;
            }
        }
}






bool postOrderTraversalISum (TreeNode *root,int sum) {
        stack<TreeNode *> visitS;
        TreeNode *curr = root;
        int tmpSum = 0;
        while (curr || !visitS.empty() ) {
            while (curr) {
                visitS.push(curr);
                curr = curr->left;
                tmpSum += curr->val;
            }
            curr = visitS.top();
            if (tmpSum == sum && curr->left == NULL && curr->right == NULL) {
                return true;
            }
            if (curr->right && pre != curr->right) { //9 is stored in pre so while 8 poped out just go to else part
                curr = curr->right;  //# see the case 8,9
            } else {
                pre = curr;
                visits.pop();
                //Subtract the current value
                tmpSum -= curr->val;
                //cout << curr->val << " ";
                curr = NULL;
            }
        }

        return false;

}

void postOrderTraversalIUgly (TreeNode *root) {
    if (!root) {
        //cout << endl;
        return;
    } else {
        stack<TreeNode *> visitS;
        visitS.push(root);
        while (root) {
            root = root->left;
            visitS.push(root);
        }
        root = visits.top();
        while (root) {
            if (root->right) {
                root = root->right;
                visitS.push(root);
            }
        }
        while (!visits.empty()) {
            TreeNode *tmpNode = visits.top();
            visits.pop();
            cout << tmpNode->val << " ";
            if (tmpNode->right) {
                while (tmpNode) {
                    tmpNode = tmpNode->right;
                    visits.push(tmpNode);
                }
            }
        }


    }
}

void postOrderTraversalR (TreeNode *root) {
    if (!root) {
        //cout << endl;
        return;
    } else {
        postOrderTraversalR (root->left);
        postOrderTraversalR (root->right);
        cout << root->val << " ";
    }
}



int main () {

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->left->left->left = new TreeNode(3);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(21);
    postOrderTraversalR (root);
    cout << endl;
}

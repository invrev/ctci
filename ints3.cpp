
struct BTNode {
      BTNode *left; 
        
};

1
 \ 
  2


//develop all substring
//abac 
//adbc
int getEditDistance (string a,string b) {
    int m = a.length();
    int n = b.length();
    if ( m == 0) {
        return n;
    } else if (n == 0) {
        return m;
    } else {
    
        //Min edit distance
        int step1 = min ( getEditDistance (a.substr(1,a.length() - 1),b),getEditDistance (a,b.substr(1,a.length() - 1)));
        int step2 = min (step1, a[0] == b[0] ? 0 : 1 + getEditDistance (a.substr(1,a.length() - 1),b.substr(1,a.length() - 1) )    
        return step2;
    }
}  
BTNode *lca (BTNode *root,BTNode *n1,BTNode *n2) {

    if (!root) {
        return NULL;
    }
    if (root->val > n1->val && root->val > n2->val) {
        return lca (root->left,n1,n2);
    } else if (root->val < n1->val && root->val < n2->val) {
        return lca (root->right,n1,n2);
    } else {
        return root;
    }
}
int maxDepth (BTNode *root) {

    if (!root) {
        return 0;
    } 
   
    int l = maxDepth(root->left);
    int r =  maxDepth(root->right);
    if (root->left == 0 && root->right == 0) {
       return 1;
    }else if (root->right == 0) {
      return (1 + l);   
    } else if (root->left == 0) {
        return (1+r);
    } else {
        return 1 + max(l,r);
    } 
}


void getPathSum (BTNode *root,vector<vector <BTNode*> >&op,vector<BTNode *>&result,int sum) {

    if (!root) {
        return;
    } 
    if (root->data == sum &&  (root->left == NULL && root->right == NULL) ) {
        result.push_back(root);
        op.push_back(root);
        result.pop_back();
    } else {
        result.push_back(root);
        getPathSum (root->left,op,result,sum-root->val);
        getPathSum (root->right,op,result,sum-root->val);
        result.pop_back();
    }
   
}


//1001 - 1011 - 1010
int greyCode (int a,int b) {
    int next = a ^ 1;
    int prev = a ^ ( (a & ~a) << 1);
}

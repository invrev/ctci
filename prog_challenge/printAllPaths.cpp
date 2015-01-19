#include<iostream>
using namespace std;

//Given tree and sum print all the paths from any node to any node
//smells like the Topological sorting
//n choose n with repeatition : (n^n) : skiena combinotrics 
void printAllPathToSum (BTNode *root,vector<int> &result,vector<vector <int> >&path,int sum) {
     if (!root) {
        return;       
    }
    if (sum == root->value) {
        result.push_back(root->value);
        path.push_back(result);
        result.pop_back();
        return;
    }
    int val = root->value;
    if (sum - val > 0) {
        result.push_back(val);
        printAllPathToSum (root->left,result,path,sum-val);
        printAllPathToSum (root->right,result,path,sum-val);
        result.pop_back();  
    }
}

void traverseAllNodes (BTNode *root,vector<int> &result,vector<vector <int> >&path,sum) {
       printAllPathToSum (root,result,path,sum);
       traverseAllNodes (root->left);
       traverseAllNodes(root->right);
}

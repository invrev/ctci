#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;




//given tree find deepest node
//         c
//       g    a    
//     h    q   r
//   k  t       s
//
//
//c->g,a->h,q,r-> k,t : 4  


struct BTNode {
    int val;
    BTNode *left;
    BTNode *right;
    BTNode (int data) :  
        val(data),left(NULL),right(NULL)
    {

    };
};

BTNode* findDeepestNode (BTNode *root) {
    vector <pair <int,BTNode * > > u_pair;
    queue<BTNode *> tQ;
    tQ.push(root);
    int currVisited = 1;
    int nextVisited = 0;
    int level = 1;
    while (!tQ.empty()) {
        
        BTNode *tmp = tQ.front();
        if (tmp->left == NULL && tmp->right == NULL) {
            u_pair.push_back( make_pair(level,tmp) );
        }
        if (tmp->left) {
            tQ.push(tmp->left);
            nextVisited++;
        }
        if (tmp->right) {
            tQ.push(tmp->right);
            nextVisited++;
        }
        tQ.pop();
        currVisited--;
        if (currVisited == 0) {
            currVisited = nextVisited;
            level++;
        }           
    }
    
    
    int l = u_pair.size();
    pair<int,BTNode *> sample = u_pair[l-1];
    for (int i=l-2;i>=0;i--) {
        pair<int,BTNode *> tmp = u_pair[i];
        if (sample.first != tmp.first) {
            return sample.second;
        } else {
            sample = tmp;   
        }
    }
    
}


int main () {

}

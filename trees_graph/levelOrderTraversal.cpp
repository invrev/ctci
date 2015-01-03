#include<iostream>

struct BTNode {
    BTNode *left;
    BTNode *right;
    int val;
    BTNode (int aVal) : 
        val(aVal),left(NULL),right(NULL)
    {

    };
};

 

vector <vector <BTNode*> > traverseLevelOrder (BTNode *root) {
     
      vector<vector <BTNode*> > result;
      queue<BTNode *> traverseQ;
      vector<BTNode *> levelResult;
      int currentVisited = 0; //# of nodes visited in the current level
      int nextVisited = 0; //# of nodes will be vistied in the next level
      if (!root) {
          return result;
      } else {
          //Time : (o (log n) )
          //Space : O(n)
          currentVisited = 1;
          traverseQ.push(root);         //  3
          while (!traverseQ.empty()) {
              
              BTNode *tmpNode = traverse.front(); //  9:20 : 15 :7
              
              if (tmpNode->left) {
                   traverseQ.push(tmpNode->left); //3,9
                  nextVisited++;                 //1
              }
              if(tmpNode->right) {
                  traverseQ.push(tmpNode->right); //3,9,20 : 
                  nextVisited++;                    //2
              }                                     //20:15,7
              
              currentVisited--;     //1:0:1:0
              if (tmpNode) {
                  levelResult.push_back(tmpNode); //9:20 //15:7
              }
              traverseQ.pop();  //9,20 : 20 :7
              
              
              if (currentVisited == 0) {
                  currentVisited = nextVisited;  //2
                  nextVisited = 0; 
                  result.push_back(levelResult);
                  levelResult.clear();
              }          
          }
         
          return (result);
      }
 
 }

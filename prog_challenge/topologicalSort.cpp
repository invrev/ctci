#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;

//NOTE : for topological sort use DFS


    
//5->2 5->0 
//4->0,4->1
//2->3
//3->1


//4
//x1 : v        
//x3 :v    
//x0 //x2 : v 
//x5 : v

//5->2->3->1->4
//5->0->2->3
//5 4 2 3 1 0

//toplogical sort with 
void createAdjInGraph(unordered_map<int,vector<int> >& graph,int v,vector<int> adjV) {

    if ( graph.find(v) == graph.end() ) {
        graph[v] = adjV;
    } else {
        vector<int> tmp = graph[v];
        int n = adjV.size();
        for (int i=0;i<n;i++) {
            tmp.push_back(adjV[i]);
        }
        graph[v] = tmp;
    }
}


void doDFSTraverse (unordered_map<int,vector<int> >& graph,int v
                ,unordered_set<bool> &visited,vector<int>& result)  {
        stack<int> traverseS;
        traverseS.push(v);
        while (!traverseS.empty()) {
            int opV = traverseS.top();
            result.push_back(opV);
            vector<int> tmpV = graph[opV];
            for (auto &it : tmpV) {
              if (visited.find(v) == visited.end()) { 
                visited.insert(it);
                traverseS.push(it);
               }
            }
            traverseQ.pop();
         }  
}


void doBFSTraverse (unordered_map<int,vector<int> >& graph,int v
                ,unordered_set<bool> &visited,vector<int>& result)  {
        queue<int> traverseQ;
        traverseQ.push(v);
        while (!traverseQ.empty()) {
            int opV = traverseQ.front();
            result.push_back(opV);
            vector<int> tmpV = graph[opV];
            for (auto &it : tmpV) {
                visited.insert(it);
                traverseQ.push(it);
            }
            traverseQ.pop();
         }  
}


void topologicalSort(unordered_map<int,vector<int> >& graph) {
        unordered_set<bool> visited;
        vector<int> result;
        for (auto &it : graph) {
             int v = it.first;
             if (visited.find(v) == visited.end()) { 
                 visited.insert(v); 
                 doBFSTraverse (graph,v,visited,result);
             }                               
        }     
}


int main () {

}


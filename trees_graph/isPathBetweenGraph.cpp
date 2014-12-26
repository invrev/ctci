#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;


bool isPathBetweenNodes (unordered_map<int ,vector<int> >& graph,int v1,int v2) {

    //BFS traversal
    queue<int> visitedV;
    visitedV.push(v1);
    while (!visitedV.empty()) {
        int tmpV = visitedV.front();
        visitedV.pop();
        if (tmpV == v2) {
            return true;
        }
        for (int i=0;i<graph[tmpV].size();i++) {
            visitedV.push(graph[tmpV][i]);
        }
    }
    return false;
}


int main () {

}

#include<iostream>
#include<vector>
using namespace std;


void print_result (vector<int>& result) {
    int n = result.size();
    for (int i=0;i<n;i++) {
        cout << result[i] << ",";
    }
    cout << endl;
}
void generatePermutation (vector<int>&ip,int k,vector<int>& visited,vector<int>&result,vector<vector <int> >&op) {

    if (k == ip.size() ) {
        //print_result(result);
        cout << "-------------" << endl;
        print_result (visited);
        op.push_back(result);
        return;
    } else {
       for (int i=0;i<ip.size();i++) {
           //cout << "(" << i << "," << k << ")" << endl;
           cout << "(" << k <<"---" ;
           print_result (visited);
           if (visited[i] == 0) {
               //cout << k << "|";
               //print_result (visited);
               visited[i] = 1;
               //vector unware of which is pushed
               result.push_back(ip[i]);
               generatePermutation (ip,k+1,visited,result,op);
               visited[i] = 0;
               result.pop_back();
           }
       }
    }


}


int main () {

    vector<int> result;
    vector<vector <int> > op;
    //int a[] = {1,2,3};
    int a[] = {1,2};
    vector<int> ip(a,a+sizeof(a)/sizeof(a[0]));
    int n = ip.size();
    vector<int> visited (n,0);
    generatePermutation (ip,0,visited,result,op);



}

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;



int main () {

    int a[] = {1,2,3,4,5,6};
    vector <int> av (a,a+sizeof(a)/sizeof(a[0]));

    for (const auto &it:av)  {
        cout << it << "," ;
    }
    cout << endl;

    unordered_map<int,int> u_map;
    u_map[0] = 1;
    u_map[1] = 1;
    u_map[2] = 1;

    for (auto &it:u_map) {
        cout <<  "k = " << it.first  << " v = " << it.second << endl;
    }
        
    unordered_set<int> u_set;

    u_set.insert(0);
    u_set.insert(1);
    u_set.insert(20);
    u_set.insert(0);

    for (auto it:u_set) {
        cout << it << ",";
    }

    cout << endl;


}

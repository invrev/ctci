#include<iostream>
#include<utility>
#include<vector>
using namespace std;


//The input array is sorted
//Time complexity (O(n))  :If array is sorted if not sorted then O(n log n) + O(n)
vector< pair <int,int> > getPairsFromList(vector<int>& input,int sum) {

    vector< pair <int,int> > resultSet;
    int start = 0;
    int end = input.size()-1;
    while (start < end) {
        int tmpResult = input[start] + input[end];
        if (tmpResult == sum) {
            resultSet.push_back( make_pair(input[start++],input[end--]) );
        } else if (tmpResult < sum) {
            start++;
        } else {
            end--;
        }
    }

    return resultSet;
}



int main () {

    int input[] = {1,1,2,6,7,8,9};
    int sum = 10;
    vector<int> inputV (input,input+sizeof(input)/sizeof(input[0]));
    vector< pair<int,int> > r = getPairsFromList (inputV,sum);
    for (int i=0;i<r.size();i++) {
        cout << r[i].first << "," << r[i].second << endl;
    }

}

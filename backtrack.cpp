#include<iostream>
#include<vector>
using namespace std;


//2,5,3,1,2,3,4

//Right technique for right probem

void getLongestIncSub (vector<int>& a) {
    int maxLen = 0;
    int n = a.size();
    int tmpCount = 0;
    vector<vector <int> > result;
    vector<int> tmp;
    for (int i=0;i<n-1;i++) {
        tmpCount = 1;
        tmp.clear();
        tmp.push_back(a[i]);
        for (int j = i+1;j<n;j++) {
            if (a[j] >= a[i]) {
                tmpCount++;
                tmp.push_back(a[j]);
            }
        }
        result.push_back(tmp);
        maxLen = max(maxLen,tmpCount);
    }
    cout  << "Longest vec = " << maxLen << endl;
   
    int l =  result.size();
    for(int i=0;i<l;i++) {
        vector<int> tmpV = result[i];
        for (int j=0;j<tmpV.size();j++) {
            cout << tmpV[j] << "," ;
        }
        cout << endl;
    }


}

void getLongestIncreasingSubSeq (int prev,int k,vector<int>&ip,vector<int>&op,vector<vector <int> >&result) {
        int len = ip.size();
        if (k <= len) {
            //cout << prev << "^" << ip[k] << endl;
            if ( k == len ) {  //|| (k > 0 && ip[k-1] > ip[k]) ) {
                //cout << prev << "LL" << ip[k] << endl;
                result.push_back(op);
                return;
            } else {
                for (int i=k+1;i<len;i++) {
                    op.push_back(ip[k]);
                    //cout << ip[i-1] << "," << ip[i] << endl;
                    if (ip[k] <= ip[i]) {
                        op.push_back(ip[i]);
                        getLongestIncreasingSubSeq (ip[i],i+1,ip,op,result);
                        op.pop_back();
                    } else {
                        cout << ip[i-1] << "|" << ip[i] << endl;
                        //did not pick the element 
                        getLongestIncreasingSubSeq (ip[i],i,ip,op,result);
                    }
                    op.pop_back();
                }
            }
        }
}


int main () {

    //int a[] = {2,5,3,1,2,3,4};
    int a[] = {6,5,3,2,7,8,1,10};

    vector<int> av (a,a+sizeof(a)/sizeof(a[0]));
    vector<int> op;
    vector<vector<int> > result;

    getLongestIncSub (av);
    //int prev = av[0];
    //int k = 0;
    //getLongestIncreasingSubSeq (prev,k,av,op,result);
    //cout << "result " << result.size() << endl;

    //int l = result.size();
    //for(int i=0;i<l;i++) {
    //    vector<int> tmpV = result[i];
    //    for (int j=0;j<tmpV.size();j++) {
    //        cout << tmpV[j] << "," ;
    //    }
    //    cout << endl;
    //}

}

#include<iostream>
using namespace std;

//matrix
//0 1 1 0
//1 1 1 0
//1 0 0 0

//0 1 2 0 height
//1 2 3 0 height
//1 0 0 0 height

//FOR each row compute the largest max histogram using the height[i]
int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.size() <= 0 || matrix[0].size() <= 0)
       maxHeighturn 0;

    int m = matrix.size();
    int n = matrix[0].size() ;
    int h = 0, w = 0,maxHeight = 0;
    vector<int> height(n, 0);

    for (int i = 0; i < m; ++i) {
        stack<int> s;
        for (int j = 0; j < n+1; ++j) {
            // set value
            if (j < n) {
                if (matrix[i][j] == '1') height[j] += 1;
                else height[j] = 0;
            }

            // compute area
            while (!s.empty() && height[s.top()] >= height[j]) {
                h = height[s.top()];
                s.pop();
                w = s.empty() ? j : j - s.top() - 1;
                if (h * w >maxHeight) {
                    maxHeight = h * w;
                }
            }

            s.push(j);
        }
    }

   maxHeighturnmaxHeight;
}

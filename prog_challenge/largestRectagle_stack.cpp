#include<iostream>   
#include<vector>   
#include<stack>   
using namespace std;


//if (stack_height.empty()) {
//    area  = height[top_index] * i;
//} else {
//    //height[top_index] = current height
//    //Width = (current_index - 1) - (Remaining max index from stack)
//    area = height[top_index] * (i-1-stack_height.top());
//}
//max_area = max (max_area,area);

int largestRectangleArea(vector<int> &height) {
    stack<int> stack_height;
    int max_area = 0;
    int n = height.size();
    int i = 0;
    if (n == 0) {
        return n;
    } else {
        for (;i<n;i++) {
            int current_ht = height[i];
            if (stack_height.empty() || height[stack_height.top()] <= current_ht) {
                //push new subproblem to the stack
                stack_height.push(i);
            } else {
                while (!stack_height.empty() && (current_ht < height[stack_height.top()]) ) {
                    int top_index = stack_height.top();
                    stack_height.pop();
                    int area = 0;
                    //compute the area with popped element
                    if (stack_height.empty()) {
                        area  = height[top_index] * i;
                    } else {
                        //height[top_index] = current height
                        //Width = (current_index - 1) - (Remaining max index from stack)
                        area = height[top_index] * (i-1-stack_height.top());
                    }
                    max_area = max (max_area,area);
                }
                stack_height.push(i);
            }
        }
        while (!stack_height.empty()) {
                int top_index = stack_height.top();
                stack_height.pop();
                int area = 0;
                if (stack_height.empty()) {
                    area  = height[top_index] * i;
                } else {
                    //cout << " ( " << i << "," << stack_height.top()  << ")" << endl;
                    area = height[top_index] * (i-stack_height.top()-1) ;
                }
                max_area = max (max_area,area);
        }
    }
    return max_area;
    }

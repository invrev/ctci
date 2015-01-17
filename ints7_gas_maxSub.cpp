
[−2,1,−3,4,−1,2,1,−5,4]
//1,-3| 4 |

int ContMaxSum (int a[],int n) {

    if (n <= 0) {
        return INT_MIN;
    } 
    
    int maxSum = a[0];
    int localMaxSum = a[0];
    int start = 1;
    while  (start < n) {
        if (localMaxSum > maxSum) {
            maxSum = localMaxSum;
        }
        if (localMaxSum < 0) {
            localMaxSum = 0;
        }
        localMaxSum += a[start]; 
        start++; 
    } 
    return maxSum;
}
//-2 
//LMX : 0 ,1 MX = 1
//LMX : -2 , 4
//LMX : 0 , 4 , -1
//LMX : 3 + 2 MX : 5
//MX : 6

















n gas stations
 gas[i]
from gas station i to gas station i+ 1 need gas amount: cost[i]
start from a gas station, try and see if u can finish the circle (all gas stations)


car start with gas 0

 gas[i]  cost[i]  left //
0:0       2      : -2 
1:10      8      : 2 
2:5       1      : 4


//distance = ?  S = O(n) , T= O(1)
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
     
     int n = gas.size();
     vector<int> gasLeft (n,0);
     
     for (int i=0;i<n;i++) {
         gasLeft[i] = gas[i] - cost[i];
     }
     
     int canReach = 0;
     for (int i = 0;i<n;i++) {     // startStn : 1->2->0 , 2->0->1
         for (int j=0;j<n;i++) {   //1 : 2+4-2 
             int k = (i+j) % n;
             canReach += gasLeft[j];
             if (canReach < 0) {    
                 break;
             }
         }
         if (canReach >= 0) {
             return i;
         }
     }
    return -1;
 
}

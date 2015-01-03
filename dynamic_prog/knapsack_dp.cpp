#include<iostream>
using namespace std;


//A top down approach
int rec_knapsack (int a[],int val[],int item,int capacity) {

    if (capacity < 0 || item < 0 || capacity < a[item] ) {
        return 0;
    } else {
        //# of subproblems
        //pick it or not pick it
        return max ( rec_knapsack (a,val,item-1,capacity), 
                (val[item] + rec_knapsack (a,val,item-1,capacity - a[item]) ) );
    }
}

//top down approach

int dp_knapsack (int wt[],int val[],int item,int capacity) {
    
    int profit[item+1][capacity+1];
    //init stages 
    for (int i=0;i<=item;i++) {
        profit[i][0] = 0;
    }
    //init state 
    for (int j=0;j<=capacity;j++) {
        profit[0][j] = 0;
    }
    
    //compute the values
    for (int i=1;i<=item;i++) {
        for (int j=1;j<=capacity;j++) {
            if (wt[i-1] <= j) {
                //Pick the element  
                //which is max (previous state value,previous state value by adding the current state value)
                profit[i][j] = max (profit[i-1][j],val[i-1] + profit[i-1][j-wt[i-1]] );
            } else {
                //Don't pick the element
                profit[i][j] = profit[i-1][j];
            }
        }
    }
    return profit[item][capacity];
}


void dp_knapsack_backtrack (int wt[],int val[],int item,int capacity) {
    

    int profit[item+1][capacity+1];
    //init stages 
    for (int i=0;i<=item;i++) {
        profit[i][0] = 0;
    }
    //init state 
    for (int j=0;j<=capacity;j++) {
        profit[0][j] = 0;
    }
    
    //compute the values
    for (int i=1;i<=item;i++) {
        for (int j=1;j<=capacity;j++) {
            if (wt[i-1] <= j) {
                //Pick the element  
                //which is max (previous state value,previous state value by adding the current state value)
                profit[i][j] = max (profit[i-1][j],val[i-1] + profit[i-1][j-wt[i-1]] );
            } else {
                //Don't pick the element
                profit[i][j] = profit[i-1][j];
            }
        }
    }
   int line = item;
   int  j = capacity;
   //cout << item  << "," << capacity << endl;
   //cout << profit[item][capacity] << endl;
   while (line > 0)  {
       if (profit[line][j] >  profit[line - 1][j] )  {
           cout << "element " << line-1 << "|" << profit[line][j] <<  endl;
           j -= wt[line - 1];
           line = line - 1;
       } else if (profit[line][j] == profit[line - 1][j]) {
           line = line - 1;
       }
   }
}








int main () {
    //int val[] = {60, 100, 120};
    //int wt[] = {10, 20, 30};
    //int  W = 50;

    //int val[] = {1,6,18,22,28};
    //int wt[] = {1,2,5,6,7};
    //int  W = 11;

    int val[] = {5,4,4};
    int wt[] = {5,4,4};
    int  W = 8;
    
    int no_of_items = sizeof(val)/sizeof(val[0]);
    int max = rec_knapsack (wt,val,no_of_items -1 ,W);
    cout << "the max profit " << max << endl;
    max = dp_knapsack (wt,val,no_of_items,W);
    cout << "the max profit " << max << endl;

    dp_knapsack_backtrack (wt,val,no_of_items,W);
    //observations
    //cannot take the item with W >

}

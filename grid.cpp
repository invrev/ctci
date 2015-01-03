#include<iostream>
using namespace std;


void printSnakeOrder (int a[][4]) {

    for (int i=3;i>=0;i--) {
        for (int j=0;j<=3-i;j++)  {
            cout << m[j][i+j] << "," ;
        }
        cout << endl;
    }

    //int m = 3;
    //int n = 3;
    //for (int i=0;i<m;i++) {
    //    for (int j= 0;j<n;j++) {
    //        int tmp = j + ( (m-2*j) * ((i) % 2));
    //        cout << a[i][tmp] << ",";
    //    }
    //    cout << endl;
    //}
}

int main () {

    int m [][4] = { {1,2,3,4}
                    ,{5,6,7,8} 
                    ,{9,10,11,12} 
                    ,{13,14,15,16} 
                  };
    printSnakeOrder (m);

}

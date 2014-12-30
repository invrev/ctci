#include<iostream>
using namespace std;


int CoinChange(int coins[],int n,int amt,int k) {
    if (amt < 0) {
        return 0;
    } else if (amt == 0) {
        return 1;
    } else if (k < 0) {
        return 0;
    }else {
        return CoinChange (coins,n,amt-coins[k],k) + CoinChange (coins,n,amt,k-1) ;
    }

}

int main () {

    int coins[] = {1,10,25};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amt = 2;
    int k = 2;
    int ways = CoinChange(coins,n,amt,k);
    cout << "# os ways to get (" << amt << ")" << " = " << ways << endl;
}

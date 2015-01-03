#include<iostream>
#include<cstdlib>
using namespace std;

void shuffleCard(int card[]) {

    for (int i=0;i<52;i++) {
        int next = i + ( rand() % (51 - i) );
        swap(card[i],card[next]);
    }

}


void shuffleCardWR(int card[]) {

    for (int i=51;i>=0;i--) {
        int next =  1 + ( rand() % (52 - i) );
        swap(card[i],card[next]);
    }

}

int main () {

}

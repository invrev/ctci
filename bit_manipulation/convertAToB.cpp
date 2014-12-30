#include<iostream>

int convertAtoB (int a,int b) {

    //Get the diff bits by XOR 
    int diff = a ^ b;
    int count = 0;
    while (diff != 0) {
        diff = diff & (diff - 1);
        count++;
    }
    return count;
}

int main () {

}

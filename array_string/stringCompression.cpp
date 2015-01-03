#include<iostream>
#include<string>
using namespace std;


//Find intersection of array

//Find union of array

//Using map and w/o sorting

//combine k sorted array
//combine 2 sorted array
//copy the tree
//copy the posting list
//Remove the duplicate from linked list
//

//string compression
//If "AAABBAAA" the resultant string should be 3A2B3A.

void stringCompression (string &input) {
    int len = input.length();
    int start = 1;
    int count = 1;
    string result = "";
    while (start <= len) {
        if (input[start] == input[start - 1]) {
            count++;
        } else {
            result += to_string(count);
            result += input[start - 1];
            count = 1;
        }
        start++;
    }
    cout << result << endl;
    
}


int main () {
 string ip = "AAABBAAA";
 stringCompression (ip); 

}

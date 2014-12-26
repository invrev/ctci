#include<iostream>
#include<cstring>
using namespace std;


void reverseString (char *str) {
    if (str != '\0') {
        cout << " " << str+1 << endl;
        str = str+1;
        reverseString (str);
        //return strcat(reverseString (tmp),str);
    } 
    //else {
    //    //return str;
    //}
}

//Note the C-String in array of characters
void reverseStringIter (char *str) {
    int start = 0; 
    int end = 0;  
    while (str[end+1] != '\0') {
        end = end + 1;
    }
    while (start != end) {
        swap (str[start],str[end]);
        start++;
        end--;
    }
}

int main () {
    char str[] = "hello";
    reverseStringIter (str);
    cout << "stringi Rev =" << str << endl;
    reverseString (str);
    //cout << "reverse of str = "<<  str << "=" << op << endl;
}

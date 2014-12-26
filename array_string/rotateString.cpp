#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//, “waterbottle” is a rotation of “erbottlewat”

//s2 = s2 + s2 and use strstr


bool isStringRotation (string& s1,string& s2) {

    if (s1.length() == s2.length()) {
        //update the string
        s2 += s2;

        //strstr (const char* SOURCE, const char* TARGET )
        //Finds the first occurrence of the byte string TARGET 
        //in the byte string pointed to by SOURCE. 
        //The terminating null characters are not compared.
        if (strstr(s2.c_str(),s1.c_str()) != NULL ) {
            return true;
        }
    } 
    return false;
}

void test (string s1,string s2) { 
    if ( true == isStringRotation (s1,s2) ) {
        cout <<  "(" << s1 << "," << s2 << ") " << "are in rotation"  << endl;
    } else {
        cout <<  "(" << s1 << "," << s2 << ") " << "are not in rotation"  << endl;
    }
}


int main () {
    test("waterbottle","erbottlewat");
    test("waterbottl1","1rbottlewat");
}

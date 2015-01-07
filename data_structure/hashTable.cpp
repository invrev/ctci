#include<iostream>
#include<string>
using namespace std;

//Used in the symbol table

struct HashTable {
    string key;
    string value;
    HashTable *next;
    HashTable (string aKey,string aValue) : 
        key(aKey),value(aValue),next(NULL)
    {

    };
};


int main () {
  
    HashTable ht[10] ;


}

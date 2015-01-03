#include<iostream>
using namespace std;


struct Node {
    int data;
    Node* small;
    Node* large;
    Node (int aVal) : 
        data(aVal),small(NULL),large(NULL)
    {

    };

};


void join(Node* a, Node* b) {
    a->large = b;
    b->small = a;
}


/*
 helper function -- given two circular doubly linked
 lists, append them and return the new list.
*/
Node* append(Node* a, Node* b) {
    Node* aLast;
    Node* bLast;
    
    if (a== NULL) return(b);
    if (b== NULL) return(a);
    
    aLast = a->small;
    bLast = b->small;
    
    join(aLast, b);
    //aLast->large = b;
    //b->small = aLast;

    join(bLast, a);
    //bLast->large = a;
    //a->small = bLast;
    
    return(a);
}



Node* treeToList(Node* root) {
    Node* aList;
    Node* bList;
    
    if (root==NULL) { 
        return(NULL); 
    }

    /* recursively solve subtrees -- leap of faith! */
    cout << "s = " << root->data << ","<< root->small << endl;
    aList = treeToList(root->small);

    cout << "l = " <<  root->data << "," <<  root->small << endl;
    bList = treeToList(root->large);
    
    /* Make a length-1 list ouf of the root */
    root->small = root;
    root->large = root;

    /* Append everything together in sorted order */
    cout << "eval aList0000" << endl;
    aList = append(aList, root);

    cout << "eval aList1111" << endl;
    aList = append(aList, bList);
    
    return(aList);
}



void printList(Node* head) {
    Node* current = head;
    
    while(current != NULL) {
        cout << current->data << " ";
        current = current->large;
        if (current == head) break;
    }
    cout << endl;
}


int main () {
    
    Node *root = new Node (4);
    root->small = new Node (2);
    root->large = new Node (5);
    root->small->small = new Node (1);
    root->small->large = new Node (3);
   
    Node *tmp;
    tmp = treeToList(root);
    printList(tmp);

}


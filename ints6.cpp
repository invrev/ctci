
BigInteger()
 
//1->2->5     (512)
//3->4->5->6  (6543)
--------------
//4->6->0->7
//(7064)

struct BigInteger {
    int num;
    BigInteger *next;
    BigInteger (int num) : 
        num(num),next(NULL)
    {
    
    };  
};

//4->6->0->7

void printRec (BigInteger* head) {
    if (!head) {
        return;
    }
    printRec(head->next); 
    if (head) {
        cout << head->num;
        return;
    }
}

void printInt (BigInteger* head) {
    BigInteger* current = head;
    BigInteger *nextP = NULL;
    BigInteger *prev = NULL;
    while (current != 0) {
        nextP = current->next;
        current->next = prev;
        prev = head;
        current = nextP;
    }
    
    while (!prev) {
        cout << prev->num;
        prev = prev->next;
    }   
}


void print(BigInteger* head){
    if(head->next)==null_
        print head;
        return;
    }
    print(head-next);
    print head;
    return;

}

BigInteger add(BigInteger* a,BigInteger* b) {
    
    int carry = 0;
    BigInteger* result = new BigInteger(-1);
    BigInteger* tmpResult;
    while (a && b) {
        int result = (a->num) + (b->num)  + carry;
        carry = result / 10;
        result = result % 10;
        tmpResult->next = new BigInteger(result);
        tmpResult = tmpResult->next;
        a = a->next;
        b = b->next;
    }
    if (!a) {
        a = b;
    }
    
    while (a) {
        result = carry + a->num;
        carry = result / 10;
        result = result % 10;
        tmpResult->next = new BigInteger(result);
        tmpResult = tmpResult->next;
    }
    return (result->next);
}




//101010000011001
void seperateZerosAndOnes (int a[],int n) {

    int m = 0;
    while (a[n] == 1 && n > 0) {
        n -- ;
    }
    while (a[m] == 0 && m < n) {
        m ++;
    }
    
    while (m < n) {
        if (a[m] == 0) {
            m++;
        }
        if (a[n] == 1) {
            n--;
        } 
        if (a[m] != a[n]) {
            swap(a[m],a[n]);
            m++;
            n--;
        }
    }
}


void seperateZerosAndOnes (int a[],int n) {
    
        int pivot = a[0];
        int end = n;
        
        while 

}




//clean slate

//linked list - print reverse 
head->4-5-6->NULL
              (current)
NULL<-4<-5<-6<-head
                (prev) 


ListNode* reverseList(ListNode *head) {
    if (!head) {
        return head;
    }
    ListNode *current = head;  
    ListNode *prev = NULL;        
    while (current) {
        ListNode *nextN = current->next;
        current->next = prev;
        prev = current;
        current = nextN;
    }
    
    return prev;
}

ListNode *recReverseList (ListNode *head,ListNode *prev) {
    if (!head) {
        return prev;        
    }
    ListNode *tmp = head->next;
    head->next = prev;    
    return ( recReverseList (tmp,head) ) ;
}

//4-5-6->NULL    //4,NULL ->  (NULL<-4,5)  (6,NULL<-4<-5)  (NULL,NULL<-4<-5<-6) (break from stack)

 //4->5->6->NULL : curr  curr->next  prev   nextN
                    4      NULL      NULL
                    5                 4       5
                    6        4        5       6   
                   NULL      5        6       NULL
                             

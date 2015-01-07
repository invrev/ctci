
//[1,0,2,0,1,0]
//[1,1,0,0,2,2]
//

    
//T = O(2*n)
//S = O(C) c: # of distinct element
void sortColor (int a[],int n) {

    int color[3] = {0};
    for (int i=0;i<n;i++) {
         color[a[i]]++;            //color[0] = 3, color[1] = 2, color[2] = 1;
    }
    int current = 0;
    for (int i=0;i<3;i++) {
        int cnt = color[i];        //cnt = 3
        while (cnt > 0) {          
            a[current++] = i;     //a[] = {0,0,0,1,1,2}
            cnt--;                //3,2,1 
        }
    }
}


























//[5,5,5,5] given 5
//[1,2,3,4]--

//[1,2,3,4,5,5,5,5,5]


//T = O(n) S = O(1)
int removeKeyFromArray (int a[],int n,int key) {

    int prev = -1;
    int start = 0;
    
    for (int i=0;i<n;i++) {         //1,2,3,4,5,5,5,5,5
        start = i;                    //9
        if (a[i] == key) { 
           swap (a[start],a[++start]); // 
        } else {
            prev = i;                //2
        }
    }
    prev += 1;
    if (prev == 0) {                               
     return prev;   
    }       
    int newLen = prev + 1;
    if (prev != start) { 
        a[++prev] = NULL;     
    }
    
    return newLen;
}


//NOTE : for building heap start from n/2 to 1  (percolate all parents)
//and for heap sort start from last or n-1;  (percolate all elements)
//
//1=n        1 
//2=n     2      3 
//3=n   4   5  6   7
//4=n 8

int getLC(int n) {
    return (2n);
} 
int getRC (int n) {
    return (2n + 1);
}

int getP (int n) {
    return (n/2);
}


void shifDown (int a[],int pos,int n) {
        int l = getLC(pos);
        int largest = pos;
        if ( l <= n && a[l] > a[largest]) {
            largest = pos;
        }
        int ri =  getRC(pos);
        if ( ri <= n && a[ri] > a[largest]) {
            largest = ri;
        }
        if (largest != n) {
            swap (a[largest],a[pos]);
            shifDown (a,largest,n);
        }
}
//Start from half of the array as will compare each node against child
void buildHeap (int a[],int n) {
    for (int i=n/2;i>=0;i--) {
        shifDown (a,i,n);
    }
}

void heaport (int a[],int n) {
    for (int i=n-1;i>=1;i--) {
        cout << a[i];
        swap (a[1],a[i]);
        shifDown (a,1,i-1);    
    }
}

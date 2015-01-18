
//2 6 15 10 4 3

int partition (int a[],int start,int end) {
    int pV = a[end];
    int pI = start - 1;
    while (start < end) {
        if (a[start] <= pivot) {
            swap(a[++pI],a[start]);
        }
        start++;
    }
    
    swap(a[++pI],a[end]);
    return pI;

}



void quickSort (int a[],int start,int end) {
    
    //Recusively find the pivot and perform the sorting
    int pivot = partition(a,start,end);
    quickSort (a,start,pivot - 1);
    quickSort(a,pivot+1,end);
}



void sort (int a[],int n) {

    if (n <= 1) {
        return ;
    }
    else if (n == 2) {
        int tmpMin = min(a[0],a[1]);
        int tmpMax = max(a[0],a[1]);
        a[0] = tmpMin;
        a[1] = tmpMax;
        return ;
    }
    
    quickSort (a,n);
    
}

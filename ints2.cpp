
//Given sorted array find the intersection

T = O(n^2) , S O(n)

bool binSearch (vector<int>&a ,int key,int start,int end) {

    while (end > start) {
        int mid = start + ( (end - start)/2 );
        if (a[mid] == key) {
            return true;
        } else if (a[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}


//sort the array O(n log n)
//iter + bin search O (n * logn)
unordered_set<int> findIntersection (vector<int>& a,vector<int>& b) {

    unordered_set<int> result;
    int aLen = a.size();
    int bLen = b.size();
    if (aLen == 0 || bLen == 0 ) {
        return result;
    }
    sort(a.begin(),a.end());
    int index = 0;
    O(n)
    for (int i=0;i<bLen;i++) {
         if  (true == binSearch(a,b[i],start,end) ) {
             result.insert(b[i]);
         }
    }
    //O(n^2)
    for (int i=0;i<aLen;i++) {
        if ( result.find(tmp) == result.end() ) {
            for (int j=0;j<bLen;j++) {
               if (tmp == b[j]) {
                   result.insert(tmp);
                   break;
               }
            }
        }
    }

    return result;
}

//2,1,3,4,5,5,5
//6,5,5,5

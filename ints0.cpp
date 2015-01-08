
//()[]{)}

//left right
//leftB++ > rightB--
//leftP++ > rightP--
//leftS++ > rightS-- 
//{({{{ )


//T(n) , S(n)
bool isValid (string &input) {
    stack<char> tStack;
    unordered_map<char,bool> l_map;
    l_map.put('{',true);  
    l_map.put('(',true);  
    
    unordered_map<char,bool> r_map;
    r_map ['}'] = true;  
    r_map.[')'] = true;  
    
    unordered_map<char,char> t_map;
    t_map ['{'] =  '}';
    
    int start = 0;
    int end = input.lenght();
    while (start < end) {
        char ip = input[i];
        if ( l_map.find(ip) != l_map.end() ) {
            tStack.push(ip);
        } else if (r_map.find(ip) != r_map.end()) {
            char leftOp = tStack.top(); // ( { [
            char actualRightOp = t_map[leftOp];
            if (actualRightOp != ip ) {
                return false;
            }
        }
    }
    
    if  ( ! tStack.empty () ) {
        return false;
    }
    
    return true;
} 









//n from 1 to n

// 3
 1
  \
   2
    \
     3
     
 //n =  (i-1) i (n-i)
 //# trees = i (1 to n) (1Ci-1 * 1Cn-i)
 
 //3 = (1 to 3) ()
 // 
 
 O(n)
 // 3 = (1 : n)  1: k = n+1/2
 int numberOfTrees (int n,int k) {
     
     
     int totalNumberOfTrees = 0;
     if (n <= 0) {
         return 0;
     } else if ( n < 2) {
         return n;
     } else {
         totalNumberOfTrees += numberOfTrees(n,k-1) * numberOfTrees(n,n-k) ; 
         return totalNumberOfTrees;
     }
     
 }
 
 //n = 3 // 5
 //0,1 * 2 = 2,
     
 
 
 

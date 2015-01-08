
-Binary trees/AVL trees, what can you tell me about them.
-Given two texts, x and y, where x < y, check if all the characters of x are in y.

-Given a string, find the longest repeating substring.

//xyyyyxyz
//xyz
//T(n) = O(n^2) and S = O(1)
//T(n) = O(n) S = (n)
bool checkOccurence (string &x,string &y) {
    
    int patLen = x.length();
    int textLen = y.length();
    if (patLen >= textLen ) {
        return false;
    }
    unordered_map<char,bool> patMap;
    for (int i=0;i<patLen;i++) {
        char toMatch = x[i];
        patMap[toMatch] = true;
    }
    for (int j=0;j<textLen;j++) {
         if (patMap.find(y[j]) == patMap.end() ) {
                return false;
            }
    }
    return true;
}





//Longest repeating substring
//1.Sliding approach
//2.Max repeated string have length 1/2
//abcbabc
// abcbabc
// 
bool findLongestSubstring(string &ip) {
    int len = ip.length();
    
    for (int i=0;i<len;i++) {
        for ()
    }
    
}



string longestSubstring (string &ip) {
    int len = ip.length();
    
    int start = 1;
    int end = len / 2;
    while (end > start) {
        string matchStr = ip.substr(0,end);
        int nextLen = matchStr.length();
        for (int i=nextLen;i<n;i+= nextLen) {
            if ( ip.substr(i,nextLen) == matchStr) {
                 return matchStr;   
            }
        }
       end -= 1;
    }
}

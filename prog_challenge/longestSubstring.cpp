
//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for “abcabcbb” is “abc”, which the length is 3. For “bbbbb” the longest substring is “b”, with the length of 1

//abbbbabcd
pair<int,int> findLongestSubstring (string input) {
    char store[26];
    memset(store,0,26*sizeof(store[0]));
    int maxLen = -1;
    int start = -1;
    pair<int,int> result = make_pair(maxLen,start);
    int len = input.length();
    for (int i=0;i<len;i++) {
        if (store[ input[i] - 'a'] != 0 ) {
          if (result.first < maxLen) {
              result.first = maxLen;
              result.second = start;
          }    
          memset(store,0,26*sizeof(store[0]));   
          maxLen = 0;
          start = i;
        }
       maxLen++;
       store[input[i] - 'a']++;
    }
}

//Given a string S, find the length of the longest substring T that contains at most two distinct characters.
//For example,
//Given S = “eceba”,
//T is "ece" which its length is 3.

pair<int,int> findLongestSubstring (string input) {
    char store[26];
    memset(store,0,26*sizeof(store[0]));
    int maxLen = -1;
    int start = -1;
    pair<int,int> result = make_pair(maxLen,start);
    int len = input.length();
    for (int i=0;i<len;i++) {
        int distCount = 0;
        for (int i=0;i<26;i++) {
            if(store[input[i]] == 1) {
                distCount++;
            }
        }
        if (distCount > 2) {
          if (result.first < maxLen) {
              result.first = maxLen;
              result.second = start;
          }    
          memset(store,0,26*sizeof(store[0]));   
          maxLen = 0;
          start = i;
       }
       maxLen++;
       store[input[i] - 'a']++;
    }
}

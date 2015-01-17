#include<iostream> 
#include<string>

//1.partition and swap
//great rgtae

//gre at | rgt ae

//abc | acb 
//a bc | a cb
//ab c | ac b


bool isScramble(string s1, string s2) {
    if(s1.length() != s2.length())  {
        return false;
    }
    if(s1 == s2)  { 
        return true; 
    }
    int store[26]; 
    memset(store,0,26*sizeof(store[0]));
    for (int i=0;i<s1.length();i++) {
        store[s1[i]- 'a']++;
    }
    
    for (int i=0;i<s2.length();i++) {
        store[s2[i] -'a']--;
    }
    
    for (int i=0;i<26;i++) {
        if (store[i] != 0) {
            return false;
        }
    }
    
    //string s3 = s1;
    //string s4 = s2;
    //sort(s3.begin(),s3.end());
    //sort(s4.begin(),s4.end());
    //if(s3 != s4 )  { 
    //    return false; 
    //}
    
    
    if (s1.length() == s2.length() && s1.length() == 1  ) {
        return true;
    }
    for(int i=1; i<s1.length(); i++) {
        bool result = (isScramble(s1.substr(0,i), s2.substr(0,i)) 
                && isScramble(s1.substr(i,s1.length()-i), s2.substr(i,s2.length()-i))); 
            
       result = result || (isScramble(s1.substr(0,i), s2.substr(s2.length()-i,i)) 
                && isScramble(s1.substr(i,s1.length()-i), s2.substr(0, s2.length()-i)));
        if(result ) {
            
            return true;
        }
    }
    return false;
    }

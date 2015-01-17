#include<iostream>
//abc
//ab
//a
//With O(n^2) and using the negated apprach  ~if (resulSet[i].length() > end && CommanPrefix == resulSet[i][end]) 
string findCommonPrefix (string[] resultSet,int n) { 
   int end = 0;
   string tmpStr;
   for (int j=0;j<resulSet[i].length(;j++) {
       char CommanPrefix = resulSet[0][j];
       for (int i = 1;i<n;;i++) {
           if (resulSet[i].length() <=j && CommanPrefix != resulSet[i][j]) {
               end = j;
               break;
            }
        } 
        if (end != 0) {
            tmpStr = resultSet[0];
            return  tmpStr.substr(0,end+1);
        }
    }   
    return tmpStr;
}

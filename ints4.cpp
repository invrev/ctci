
Given s = "    the                  sky    is blue "

blue is sky the

the sky is blue
eht        yks     si eulb

blue                      the
O(n),
string reverseString (string &ip) {

    int start = 0;
    int end = ip.length();
    int lastStart = 0;
    while (ip[start] == ' ') {
        start++;
    }
    string ip1 = ip.substr(start,end-start+1);
    ip = ip1;
    end = ip.length();
    while (ip[end] == ' ') {
        end -= 1;
    }
    string ip1 = ip.substr(0,end+1);
    ip = ip1;
    start = 0;
    end = ip.length();
    while (start < end) {
         int tmpEnd = 0;
         if ( (lastStart - tmpEnd) >= 1 && ip[start++] == ' ') {
             tmpEnd = start;
             while (lastStart < tmpEnd) {
                 swap (ip[lastStart++],ip[tmpEnd--]);
             }
         } else if ( (lastStart - tmpEnd) < 1 && ip[start++] == ' ' ) {
              lastStart = start;
              tmpEnd = start;
         }
    }
    start = 0;
    while (start < end) {
        swap(ip [start++],ip[end--]); 
    }
    start = 0;
    end = ip.length();
    int reqSpace = 1;
    while (start < end) { 
         if (reqSpace == 1 && ip[start++] == ' ') {
            reqSpace += 1;
         }else if (reqSpace > 1 && ip[start++] == ' ' ) {
             int tmpStart = start;
             while (ip[start] == ' ') {
                 start += 1;
             }
             while (ip[start] != ' ') {
                 swap (ip[tmpStart++],ip[start++])
             }
            reqSpace = 2;
         }
    }
    
    start = 0;
    end = ip.length();
    
    while (start < end) {
        if (ip[start] == ' ' && ip[start + 1] == ' ' ) {
            break;
        }
    }
    
    return ip.substr(0,start+1);
}



















min ( {x,y+1}, {x+1,y+1})
 
[
 [2],   : 2
 [3,4], : 5,6 
 [6,5,7], :10,11,11
 [4,1,8,3] :11,12,12,14
]

//2 - 3 -5
//2-3-

int minPathSum (vector <vector <int> >&grid) {

    int n = grid.size();
    vector<int> opt(n,0);
    opt[0] = grid[0][0];
    for (int i=1;i<n;i++) {
         int m = grid[i].size();
         int k = 0;
         for (int j=0;j<m-1;j++) {
            int tmp = opt[j];
            opt[j] =  min(opt[j] + grid[i][j],opt[j] + grid[i][j+1]);  //5+6,5+10
            if (j-1 >= 0) {
                opt[j] = min (opt[j],tmp + grid[i][j-1]);
            } 
            k = j;  
         }
         opt[++k] = opt[i] + grid[i][k];
    }
   int minV = INT_MAX;
   for (int i=0;i<opt.size();i++){
       minV = min(opt[i],minV);
   }
   
   return minV;
   
}

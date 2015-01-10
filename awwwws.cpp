
//(0,0) - >(x+1,0) -> (0,y+1)


//c++
//([x,y])
//x,y = (0,0)
 void getNumberOfPath (vector<vector <int> >&grid,int &steps,int x,int y) {
    int n = grid.size(); //n : # of rows    
    if (n == 0) {
        return;
    }
    int row [] = {1,0}; 
    int col[] =  {0,1};
    int len = sizeof(row)/sizeof(row[0]); 
    int m = 0;
    if (n > 0) {
        m = grid[0].size(); 
    }
    if (x == n-1 && y == m -1) {
        steps = steps + 1;
        return;
    }
    if ( (x < n && y < m) && (x >= 0 && y >= 0)  ) {   //pruning 
        for (int i=0;i<len;i++) {
            getNumberOfPath (grid,steps,row[i]+x,col[i]+y); 
        }
    }
}

//     0,0 
//   /    |
// (1,0)  (0,1)     (A)---  
   /  |    /  \
// 2,0 1,1    (1,1) (0,2)        (c)
  /
 (3,0)  
 / x+1,0
   0,y+1
 //,top,bottom
 
You are given a matrix n*m where n represents the number of rows and m represents the columns. Output the number of unique paths from|| given that at each point you can only either move right or down. 

As an example given below is a 3*2 matrix

  0 1 
0 A B  //[0,0] -> [1,0]
1 C D     - > [0,1]
2 E F

The total number of unique paths from (0,0)A to (2,1)F are : 3
1. A->B->D->F
2. A->C->D->F
3. A->C->E->F

Here are examples of other types of Matrices. 

  0 1 2 3 4 
0 A B C D E
1 F G H I J
2 K L M N O

  0 1 2 3 
0 A B C D
1 E F G H
2 I J K L

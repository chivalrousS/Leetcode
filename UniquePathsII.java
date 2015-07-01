package leetcode;
/*
 * Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
 */

public class UniquePathsII {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0] ==1) return 0;  
        int m = obstacleGrid.length;  
        int n = obstacleGrid[0].length;  
        int[] step = new int[n];  
        step[0] = 1;  
        for(int i=0;i<m;i++){  
            for(int j=0;j<n;j++){  
                if(obstacleGrid[i][j]==1)  
                    step[j] = 0;  
                else if(j>0){  
                    step[j] = step[j-1]+step[j];  
                }  
            }  
        }  
        return step[n-1];  
    }
}

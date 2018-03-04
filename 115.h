class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int dp[100][100];
        
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++)
                dp[i][j] = 0;
        }
        dp[0][0] = 1;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if (obstacleGrid[i][j] == 1) 
                    dp[i][j] = 0;
                else{
                    if(i > 0) 
                        dp[i][j] += dp[i-1][j];
                    if (j > 0) 
                        dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }
};
class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int r = grid.size();
        int c = grid[0].size();
        for(int i = 0;i < r;i++){
            for (int j = 0;j < c;j++){
                if(i == 0 && j == 0) continue;
                int left = i-1 < 0 ? INT_MAX : grid[i-1][j];
                int up = j-1 < 0 ? INT_MAX : grid[i][j-1];
                grid[i][j] += min(left,up);
            }
        }
        return grid[r-1][c-1];
    }
};

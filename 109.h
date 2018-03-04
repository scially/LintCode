class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        
        // dfs TLE
        // int best = INT_MAX;
        // dfs(triangle, 0, 0, 0, best);
        // return best;
        
        // divide TLE
        //return divide(triangle, 0, 0);
    
        // divide + hash
        // 实际上这也是一中动态规划，带记忆搜索的
        // vector<vector<int>> hash = triangle;
        // for(int i = 0; i < hash.size(); i++){
        //     for(int j = 0; j < hash[i].size(); j++){
        //         hash[i][j] = INT_MAX;
        //     }
        // }
        // return divide_hash(triangle, 0, 0, hash);
        
        // 动态规划 自底向上
        // int n = triangle.size();
        // vector<vector<int>> f = triangle; // 用triangle的size初始化f
        // for(int i = 0; i < f[n-1].size(); i++){
        //     f[n-1][i] = triangle[n-1][i]; 
        // }
        // for(int i = n-2; i >= 0; i--){
        //     for(int j = 0; j < triangle[i].size(); j++){
        //         // 当前节点的值 只取决于跟他直接相连的两个节点
        //         f[i][j] = triangle[i][j] + min(f[i+1][j], f[i+1][j+1]);
        //     }
        // }
        // return f[0][0];
        
        // 动态规划 自顶向下
        int n = triangle.size();
        vector<vector<int>> f = triangle;   // 此时对于f来说，每行两端的元素已经与triangle的相同
        for(int i = 1; i < n; i++){ 
            // 初始化每行两端元素
            f[i][0] += f[i-1][0];
            f[i][f[i].size()-1] += f[i-1][f[i-1].size()-1];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < f[i].size() -1; j++){
                f[i][j] = triangle[i][j] + min(f[i-1][j-1], f[i-1][j]);
            }
        }
        int minsum = INT_MAX;
        for(int i = 0; i < f[n-1].size(); i++){
            minsum = min(minsum, f[n-1][i]);
        }
        return minsum;
    }
    void dfs(vector<vector<int>> &triangle, int x, int y, int sum, int &best){
        if(x == triangle.size()){
            best = min(best, sum);
            return;
        }
        
        dfs(triangle, x+1, y, sum+triangle[x][y], best);
        dfs(triangle, x+1, y+1,sum+triangle[x][y], best);
    }
    
    int divide(vector<vector<int>> &triangle, int x, int y){
        if(x == triangle.size()){
            return 0;
        }
        
        return triangle[x][y] + min(divide(triangle,x+1,y),
                                    divide(triangle,x+1,y+1));
    }
    
    int divide_hash(vector<vector<int>> &triangle, int x, int y, vector<vector<int>> &hash){
        if(x == triangle.size()) return 0;
        
        if(hash[x][y] != INT_MAX)
            return hash[x][y];
        
        hash[x][y] = triangle[x][y] + min(divide_hash(triangle, x+1, y, hash), 
                                          divide_hash(triangle, x+1, y+1, hash));
        
        return hash[x][y];
    }
};

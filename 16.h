class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        
        // 递归版
        sort(nums.begin(), nums.end());
        vector<vector<int>> r;
        vector<int> v;
        vector<bool> visited(nums.size(), false);
        permute(nums, r, v, visited);
        return r;
    }
    
    void permute(vector<int> &nums, vector<vector<int>> &r, vector<int> &v, 
                 vector<bool> &visited){
        if(v.size() == nums.size()){
            r.push_back(v);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            // 当越过i-1访问i的时候，如果i和i-1的重复了，但是i-1还没有被加入
            // 那i就不改被访问
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
            if(!visited[i]){
                v.push_back(nums[i]);
                visited[i] = true;
                permute(nums, r, v, visited);
                v.pop_back();
                visited[i] = false;
            }
            
        }
    }
};
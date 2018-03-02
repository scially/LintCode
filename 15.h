class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        
        // 递归版
        // vector<vector<int>> r;
        // vector<int> v;
        // permute(nums, r, v);
        // return r;
        
        // 非递归版
        vector<int> v;
        vector<vector<int>> r;
        queue<vector<int>> q;
        q.push(v);
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            if(tmp.size() == nums.size()){
                r.push_back(tmp);
                continue;
            }
            for(int i = 0; i < nums.size(); i++){
                if(find(tmp.begin(), tmp.end(), nums[i]) == tmp.end()){
                    tmp.push_back(nums[i]);
                    q.push(tmp);
                    tmp.pop_back();
                }
            }
        }
        return r;
    }
    
    void permute(vector<int> &nums, vector<vector<int>> &r, vector<int> &v){
        if(v.size() == nums.size()){
            r.push_back(v);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(find(v.begin(), v.end(), nums[i]) != v.end())
                continue;
            v.push_back(nums[i]);
            permute(nums, r, v);
            v.pop_back();
        }
    }
};
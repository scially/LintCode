class Solution {
public:
    /*
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        
        // 递归版
        // vector<vector<int>> v;
        // vector<int> r;
        // subsets(nums, r, v, 0);
        // return v;
        
        
        // 非递归
        sort(nums.begin(), nums.end());
        queue<vector<int>> q;
        vector<vector<int>> r;
        
        q.push(vector<int>());
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            r.push_back(v);
            for(int i = v.size(); i < nums.size(); i++){
                if(v.size() == 0 || v[v.size() - 1] < nums[i]){
                    v.push_back(nums[i]);
                    q.push(v);
                    v.pop_back();
                }
            }
        }
        return r;
    }
    
    void subsets(vector<int> &nums, vector<int> &r, vector<vector<int>> &v,
                 int start){
    
        v.push_back(r);
        for(int i = start; i < nums.size(); i++){
            r.push_back(nums[i]);
            subsets(nums, r, v, i+1);
            r.pop_back();
        }
        
    }
    
    
};
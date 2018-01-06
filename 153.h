class Solution {
public:
    /*
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<int> r;
        vector<vector<int>> res;
        
        sort(num.begin(), num.end());
        combinationSum2(num, target, 0, r, res);
        return res;
    }
    
    void combinationSum2(const vector<int> &num, int target, int start,
                         vector<int> &r, vector<vector<int>> &res){
        
        if(target == 0){
            res.push_back(r);
            return;
        }
        for(int i = start; i < num.size(); i++){
            //num中可能会有重复元素
            if(i > start && num[i] == num[i-1]) continue; 
            if(num[i] > target) break;
            
            r.push_back(num[i]);
            combinationSum2(num, target-num[i], i+1, r, res);
            r.pop_back(); //回溯
        }
    }
};
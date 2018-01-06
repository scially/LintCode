class Solution {
public:
    /*
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> r;
        sort(candidates.begin(), candidates.end());
        
        combinationSum(candidates, target, 0, r, res);
        return res;
    }
    
    void combinationSum(const vector<int> &candidates, int target, int start, 
                        vector<int> &r, vector<vector<int>> &res){
        if(target == 0){
            res.push_back(r);
            return;
        }
        
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] > target) break;
            
            r.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, r, res);
            r.pop_back();
        }
    }
};
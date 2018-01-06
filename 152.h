class Solution {
public:
    /*
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        // write your code here
        vector<vector<int>> res;
        vector<int> r;
        combine(n, k, 1, r, res);
        return res;
    }
    
    void combine(int n, int k, int start, 
                 vector<int> &r, vector<vector<int>> &res){
        
        if(k == 0){
            res.push_back(r);
            return;
        }
        
        for(int i = start; i <= n; i++){
            r.push_back(i);
            combine(n, k-1, i+1, r, res);
            r.pop_back();
        }
    }
};
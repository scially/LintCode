class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<pair<int,int>> diff(1, pair<int,int>(nums[0],0));
        for(int i = 1; i < nums.size(); i++){
            diff.push_back(pair<int,int>(diff[i-1].first+nums[i],i));
        }
        sort(diff.begin(), diff.end(), compare);
        int m = INT_MAX;
        vector<int> ret(2,0);
        for(int i = 1; i < diff.size(); i++){
            int num1 = diff[i].first;
            int num2 = diff[i-1].first;
            
            int index_end1 = diff[i].second;
            int index_end2 = diff[i-1].second;
            if(abs(num1-num2) < m){
                m = abs(num1-num2);
                ret[0] = min(index_end1, index_end2) + 1;
                ret[1] = max(index_end1, index_end2);
            }
        }
        return ret;
    }
    
    static bool compare(const pair<int,int> &l, const pair<int,int> &r){
        return l.first < r.first;
    }
};
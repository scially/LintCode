class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    int minSubArray(vector<int> &nums) {
        // write your code here
        int _min = nums[0], cur = nums[0];
        for(int i = 1;i < nums.size(); i++){
            if(cur > 0) cur = nums[i];
            else cur += nums[i];
            _min = min(_min, cur);
        }
        return _min;
    }
};
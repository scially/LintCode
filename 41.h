class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int _max = nums[0], d= nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(d + nums[i] < nums[i]){ 
                //一个新的区间，可改为if(d<0)
                d = nums[i];
            }
            else{
                d += nums[i];
            }
            _max = max(d, _max);
        }
        return _max;
    }
};

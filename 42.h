class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        // write your code here
        int lmax[nums.size()];
        int rmax[nums.size()];
        lmax[0] = nums[0];
        rmax[nums.size()-1] = nums[nums.size()-1];
        
        int cur = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(cur < 0) cur = nums[i];
            else cur += nums[i];
            lmax[i] = max(lmax[i-1], cur);
        }
        
        cur = nums[nums.size()-1];
        for(int i = nums.size()-2; i >= 0; i--){
            if(cur < 0) cur = nums[i];
            else cur += nums[i];
            rmax[i] = max(rmax[i+1], cur);
        }
        
        int ret = INT_MIN;
        // 到最后一个元素前位置，保证右端区间至少有一个元素
        for(int i = 0; i < nums.size()-1; i++){
            ret = max(lmax[i]+rmax[i+1], ret);
        }
        return ret;
    }
    
};
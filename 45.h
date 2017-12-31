class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        int lmax[size], lmin[size], rmax[size], rmin[size];
        lmax[0] = lmin[0] = nums[0];
        rmax[size-1] = rmin[size-1] = nums[size-1];
        
        int cur_max = nums[0], cur_min = nums[0];
        for(int i = 1; i < size; i++){
            if(cur_max < 0) cur_max = nums[i];
            else cur_max += nums[i];
            lmax[i] = max(lmax[i-1], cur_max);
            
            if(cur_min > 0) cur_min = nums[i];
            else cur_min += nums[i];
            lmin[i] = min(lmin[i-1], cur_min);
        }
        
        cur_max = nums[size-1], cur_min = nums[size-1];
        for(int i = size-2; i>=0; i--){
            if(cur_max < 0) cur_max = nums[i];
            else cur_max += nums[i];
            rmax[i] = max(rmax[i+1], cur_max);
            
            if(cur_min > 0) cur_min = nums[i];
            else cur_min += nums[i];
            rmin[i] = min(rmin[i+1], cur_min);
        }
        
        int res = INT_MIN;
        for(int i = 0; i < size-1; i++){
            res = max(res, abs(lmax[i]-rmin[i+1]));
            res = max(res, abs(lmin[i]-rmax[i+1]));
        }
        return res;
    }
};
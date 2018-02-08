class Solution {
public:
    /*
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> nums) {
        // write your code here
        int l = 0, r = nums.size();
        int __min = nums[0];
        while(l < r){
            
            int mid = l + ( r- l) / 2;
            // 右边有序
            if(nums[mid] <= nums[r-1]){
                __min = min(__min, nums[mid]);
                r = mid;
            }
            if(nums[mid] >= nums[l]){ // 左边有序
                __min = min(__min, nums[l]);
                l = mid + 1;
            }
        }
        return __min;
    }
};
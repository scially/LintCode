class Solution {
public:
    /*
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int i = 0;
        while(i < nums.size()-1 && nums[i] <= nums[i+1]) i++;
        reverse(nums,0,i);
        reverse(nums, i+1, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
        
    }
    // reverse array[l,r]
    void reverse(vector<int> &nums, int l, int r){
        while(l < r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};
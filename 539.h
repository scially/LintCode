class Solution {
public:
    /*
     * @param nums: an integer array
     * @return: 
     */
    void moveZeroes(vector<int>& nums) {
        // write your code here
        int i = -1;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[j], nums[++i]);
            }
        }
    }
};
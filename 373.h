class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int p = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1){
                swap(nums[i], nums[++p]);
                //i--;
            }
        }
    }
};
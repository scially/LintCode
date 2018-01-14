class Solution {
public:
    /*
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        for(int i = 0; i < nums.size(); i++){
            int t = target - nums[i];
            int j = binaryFind(nums, t, i, nums.size());
            if(j != -1){
                return {i+1,j+1};
            }
        }
        return {0,0};
    }
    
    // find nums[left, right)
    int binaryFind(const vector<int> &nums, int target, int left, int right){
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) right = mid;
            else left = mid + 1;
        }  
        return -1;
    }
};
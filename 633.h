class Solution {
public:
    /*
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        // write your code here
        
        // verson 1
        // sort(nums.begin(), nums.end());
        // for(int i = 1; i <nums.size(); i++){
        //     if(nums[i] == nums[i-1]) return nums[i];
        // }
        // return -1;
        
        // verson 2
        int left = 1, right = nums.size()-1;
        while(left < right){
            int count = 0;
            int mid = left + (right - left)/2;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] >= left && nums[i] <= mid)
                    count++;
            }
            if(count > mid - left + 1) right = mid;
            else left = mid+1;
        }
        return left;
    }
     
};
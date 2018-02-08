class Solution {
public:
    /*
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> nums) {
        // write your code here
        // int l = 0, r = nums.size() - 1;
        // while(l + 1 < r){
        //     int mid = l + ( r- l) / 2;
        //     if(nums[mid] > nums[l] && nums[mid] < nums[r-1])
        //         return nums[l];
        //     else if(nums[mid] == nums[r - 1])
        //         r--;
        //     else if(nums[mid] < nums[r - 1])
        //         r = mid;
        //     else  // nums[mid] > nums[r]
        //         l = mid + 1;
        // }
        // cout << l << " " << r << endl;
        // return min(nums[r],nums[l]);
        
        int l = 0, r = nums.size();
        while( l + 2 < r){
            cout << l << " " << r << endl;
            int mid = l + ( r- l) / 2;
            if(nums[mid] > nums[l] && nums[mid] < nums[r - 1])
                return nums[l];
            // 同159一样，只不过这里需要去重
            else if(nums[mid] == nums[r - 1])
                r--;
            else if(nums[mid] < nums[r - 1])
                r = mid + 1;
            else
                l = mid + 1;
        }
        cout << l << " " << r << endl;
        if(l + 1 == nums.size()) return nums[l];
        return min(nums[l], nums[l + 1]);
    }
};
class Solution {
public:
    /*
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        
        // binarySearch
        // if(nums.size() == 0) return 0;
        // int len = 1;
        // vector<int> lis(nums.size());
        // lis[0] = nums[0];
        // for(int i = 1; i < nums.size(); i++){
        //     if(nums[i] > lis[len - 1]){
        //         lis[len++] = nums[i];
        //     }
        //     else{
        //         // 这里要保证当前这个位置的数尽可能小
        //         // 这样后面才能有更多的选择“余地”
        //         int pos = binarySearch(lis, 0, len, nums[i]);
        //         lis[pos] = nums[i];
        //     }
        // }
        // return len;
        
        //dp
        if(nums.size() == 0) return 0;
        int dp[nums.size()];
        dp[0] = 1;
        int lci = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            lci = max(lci, dp[i]);
        }
        return lci;
    }
private:  
    // for binarySearch
    // nums[start, end)
    int binarySearch(const vector<int> &nums, int start, int end, int target){
        while(start < end){
            int mid = start + (end - start) / 2;
            if(target <= nums[mid])
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};
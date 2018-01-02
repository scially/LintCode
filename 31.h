class Solution {
public:
    /*
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        if(nums.size() < 1)return 0;
        return partition(nums, k, 0, nums.size()) + 1;
    } 
    int partition(vector<int> &nums, int k, int l, int r){
        // 1 三路排序
        // int lt = l - 1, gt = r;
        // int i = l;
        // while(i < gt){
        //     if(nums[i] == k){
        //         i++;
        //     }
        //     else if(nums[i] > k){
        //         swap(nums[i], nums[--gt]);    
        //     }
        //     else{ // nums[i] < k
        //         swap(nums[i], nums[++lt]);
        //         i++;
        //     }
        // }
        // return lt;
        //　2 对于本题，2路排序就可以
        int lt = l, gt = r-1;
        while(true){
            while(lt < r && nums[lt] < k) lt++;
            while(gt >= l && nums[gt] >= k) gt--;
            if(lt >= gt) break;
            swap(nums[lt++], nums[gt--]);
        }
        return gt;
    }
};
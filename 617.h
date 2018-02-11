class Solution {
public:
    /*
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        // 找到最大值和最小值
        double l = INT_MAX, r = INT_MIN;
        for(int num : nums){
            if(num < l)
                l = num;
            if(num > r)
                r = num;
        }
        
        // binary
        while((r - l) >= 1e-6){
            double mid = l + (r - l) / 2.0;
            bool search = false;
            double array[nums.size() + 1];
            double minaverage = 0;
            array[0] = 0;
            
            for(int i = 0; i < nums.size(); i++){
                array[i + 1] = array[i] + nums[i] - mid;
                
                if(i + 1 >= k && array[i + 1] - minaverage > 0){
                    search = true;
                    break;
                }
                if(i + 1 >= k){
                    // i - (k - 2) 
                    // 取k个数之前的最小值
                    minaverage = min(minaverage, array[i + 2 - k]); 
                }
            }
            
            if(search) l = mid;
            else       r = mid;
            cout << l << " " << r << endl;
        }
        
        // 这里 对于return l， 当{-1，0，1}的时候，l只是约等于0
        return r;
    }
};
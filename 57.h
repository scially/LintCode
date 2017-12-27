class Solution {
public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        vector<vector<int>> ret;
        const int target = 0;
        sort(numbers.begin(), numbers.end());
        for(int i = 0; i < numbers.size()-1; i++){
            if(i > 0 && numbers[i] == numbers[i-1]) continue; //去重
            for(int j = i + 1; j < numbers.size(); j++){
                if(j > i+1 && numbers[j] == numbers[j-1]) continue; //去重
                int sum = numbers[i] + numbers[j];
                //二分查找
                int l = j + 1, r = numbers.size();
                while(l < r){
                    int mid = l + (r - l) / 2;
                    if(numbers[mid] + sum == target){
                        //if(mid > 0 && numbers[mid] == numbers[mid - 1]) break; //去重
                        ret.push_back({numbers[i], numbers[j], numbers[mid]});
                        break;
                    }
                    else if(numbers[mid] + sum < target){
                        l = mid + 1;
                    }
                    else{
                        r = mid;
                    }
                }
            }
        }
        return ret;
    }
};
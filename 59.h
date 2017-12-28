class Solution {
public:
    /*
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        int diff = INT_MAX, ret = 0;
        sort(numbers.begin(), numbers.end());
        for(int i = 0; i < numbers.size()-1; i++){
            for(int j = i+1; j < numbers.size(); j++){
                int sum = numbers[i] + numbers[j];
                int l = j+1, r = numbers.size();
                while(l < r){
                    int mid = l + (r-l)/2;
                    if(sum + numbers[mid] == target){
                        return target;
                    }
                    else if(sum + numbers[mid] < target){
                        if(abs(sum + numbers[mid] - target) < diff){
                            diff = abs(sum + numbers[mid] - target);
                            ret = sum + numbers[mid];
                        }
                        l = mid + 1;
                    }
                    else{
                        if(abs(sum + numbers[mid] - target) < diff){
                            diff = abs(sum + numbers[mid] - target);
                            ret = sum + numbers[mid];
                        }
                        r = mid;
                    }
                }
            }
        }
        return ret;
    }
};
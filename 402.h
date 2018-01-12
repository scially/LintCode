class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        // write your code here
        
        // error
        // 本来想用两根指针指向数组前后，然后想中间靠拢，但是这样会导致部分情况
        // 没有考虑到。
        // int sum = accumulate(A.begin(), A.end(), 0);
        // int max = sum;
        // int i = 0, j = A.size()-1;
        // int max_i = i, max_j = j;
        // while(i <= j){
        //     if(max < sum){
        //         max = sum;
        //         max_i = i;
        //         max_j = j;
        //     }
        //     if(A[i] < A[j]) {
        //         sum -= A[i];
        //         i++;
        //     }
        //     else{
        //         sum -= A[j];
        //         j--;
        //     }
        // }
        // return {max_i, max_j};
    
        
        int sum = A[0], max = sum;
        int max_i = 0, max_j = 0, restart = 0;
        for(int i = 1; i < A.size(); i++){
            if(sum < 0){
                restart = i;
                sum = A[i];
                if(max < sum){
                    max = sum;
                    max_i = i;
                    max_j = i;
                }
            }
            else{
                sum += A[i];
                if(max < sum){
                    max = sum;
                    max_i = restart;
                    max_j = i;
                }
            }
        }
        return {max_i, max_j};
    }
};
class Solution {
public:
    /*
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> matrix, int k) {
        // write your code here
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[i].size(); j++)
                heap.push(matrix[i][j]);
        }
        for(int i = 1; i < k && !heap.empty(); i++){
            heap.pop();
        }
        if(!heap.empty()) return heap.top();
    }
};
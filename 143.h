class Solution {
public:
    /*
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int aux[k];
        for(int i = 0; i < k; i++){
            aux[i] = 0;
        }
        for(int i = 0; i < colors.size(); i++){
            aux[colors[i]-1]++;
        }
        for(int i = 0, j = 0; i < k; i++){
            for(int size = 0; size < aux[i]; size++){
                colors[j++] = i+1;
            }
        }
        
    }
};
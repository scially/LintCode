class Solution {
public:
    /*
     * @param n: n
     * @param k: the k th permutation
     * @return: return the k-th permutation
     */
    string getPermutation(int n, int k) {
        // write your code here
        string res = "";
        k -= 1;
        bool used[9];
        for(int i = 0; i<n; i++) 
            used[i] = false;
        
        while(true){
            if(res.size() == n) break;
            
            int p = fac(n-res.size()-1);
            int index = k / p ;
            if(k >= p){
                k %= p;
            }
            
            for(int i = 0; i < n; i++){
                if(!used[i]){
                    if(index == 0){
                        used[i] = true;
                        res += char(i + 1 + '0');
                        break;
                    }
                    else{
                        --index;
                    }
                }
            }
        }
        return res;
    }
    
    
    long long fac(int i){
        long long r = 1;
        while(i > 0)
            r *= i--;
        return r;
    }
};
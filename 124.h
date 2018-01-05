class Solution {
public:
    /*
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
        map<int,int> mp;
        int longest = 1;
        for(int i = 0; i < num.size(); i++){
            auto iter = mp.find(num[i]);
            if(iter == mp.end()){ 
                mp.insert(pair<int,int>(num[i], 1));
                if(mp.find(num[i] + 1) != mp.end()){
                    longest = max(longest, back_forward(mp, num[i], num[i]+1));
                }
                if(mp.find(num[i] - 1) != mp.end()){
                    longest = max(longest, back_forward(mp, num[i]-1, num[i]));
                }
            }
        }
        return longest;
    }
    
    int back_forward(map<int,int> &mp, int left, int right){
       int forward = left - (mp[left]-1);
       int back = right + mp[right]-1;
       int len = back - forward + 1;
       //update
       mp[back] = len;
       mp[forward]= len;
       return len;
    }
};
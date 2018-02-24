class Solution {
public:
    /*
     * @param dictionary: an array of strings
     * @return: an arraylist of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> v;
        int max_length = 0;
        for(int i = 0; i < dictionary.size(); i++){
            if(dictionary[i].size() > max_length){
                max_length = dictionary[i].size();
                v.clear();
            }
            if(dictionary[i].size() == max_length)
                v.push_back(dictionary[i]);
        }
        return v;
    }
};
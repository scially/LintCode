class Solution {
public:
    /*
     * @param words: A list of words
     * @return: Return how many different rotate words
     */
    int countRotateWords(vector<string> words) {
        // Write your code here
        set<string> s;
        for(int i = 0; i < words.size(); i++){
            bool contain = false;
            for(int j = 0; j < words[i].size(); j++){
                auto iter = s.find(words[i].substr(j+1)+words[i].substr(0, j+1));
                if(iter != s.end()){
                    contain = true;
                    break;
                }
            }
            if(!contain)
                s.insert(words[i]);
        }
        return s.size();
    }
};
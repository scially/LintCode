struct TrieNode{
    bool endword;
    TrieNode *node[26];
    TrieNode(bool end = false) : endword(end){
        for(int i = 0; i < 26; i++){
            node[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    WordDictionary(){
        root = new TrieNode;
    }
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
        // write your code here
        TrieNode *dummy = root;
        for(int i = 0; i < word.size(); i++){
            int j =  word[i] - 'a';
            if(dummy->node[j] == nullptr){
                dummy->node[j] = new TrieNode;
            }
            dummy = dummy->node[j];
        }
        dummy->endword = true;
    }

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {  // 递归寻找
        // write your code here
        return search(word, root, 0, word.length());
    }
    
    bool search(string &word, TrieNode *root, int pos, int length){
        if(root == nullptr) return false;
        if(pos == length)   return root->endword;
        if(word[pos] == '.'){
            for(int i = 0; i < 26; i++){
                if(root->node[i] != nullptr){
                    if(search(word, root->node[i], pos+1, length)){
                        return true;
                    }
                }
            }
        }
        else{  // != '.'
            int j = word[pos] - 'a';
            if(root->node[j] != nullptr){
                return search(word, root->node[j], pos+1, length);
            }
        }
        return false;
    }
private:
    TrieNode *root;
};
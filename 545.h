#define LEFTNODE(i)  (2 * (i) + 1)
#define RIGHTNODE(i) (2 * (i) + 2)
#define PARENTNODE(i)((i) > 0 ? ((i) - 1) / 2 : -1)

class Solution {
public:
    /*
    * @param k: An integer
    */Solution(int k) {
        // do intialization if necessary
        top = k;
        count = 0;
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        items.push_back(num);
        count++;
        shiftUp(count-1);
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
        vector<int> v;
        vector<int> items_cpy = items;
        for(int i = 0; i < top && count != 0; i++){
            v.push_back(extractMax());
        }
        count = items_cpy.size();
        items = items_cpy;
        return v;
    }
    
private:
    vector<int> items;
    int         count;
    int         top;
    void shiftUp(int i ){
        while(i > 0 && items[i] > items[PARENTNODE(i)]){
            swap(items[i], items[PARENTNODE(i)]);
            i = PARENTNODE(i);
        }
    }
    void shiftDown(int i){
        while(LEFTNODE(i) < count){
            int j = LEFTNODE(i);
            if(RIGHTNODE(i) < count && items[j] < items[RIGHTNODE(i)])
                j = RIGHTNODE(i);
            if(items[i] > items[j]) break;
            swap(items[i], items[j]);
            i = j;
        }
    }
    int extractMax(){
        int v = items[0];
        swap(items[0], items[count-1]);
        count--;
        items.pop_back();
        shiftDown(0);
        return v;
    }
};
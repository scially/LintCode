#define LEFTNODE(i)  (2 * (i) + 1)
#define RIGHTNODE(i) (2 * (i) + 2)
#define PARENTNODE(i) ((i) > 0 ? (((i) - 1) / 2) : -1)

class MaxHeap{
public:
    MaxHeap(const vector<int> &nums){
        items = new int[nums.size()];
        count = nums.size();
        copy(nums.begin(), nums.end(), items);
        
        int i = PARENTNODE(count - 1);
        while(i >= 0){
            shiftDown(i);
            i--;
        }
        //for(int i = 0; i < count; i++) cout << items[i] << " ";
    }
    ~MaxHeap(){
        if(items) delete[] items;
    }
    int extractMax(){
        int item = items[0];
        swap(items[0], items[count-1]);
        count--;
        shiftDown(0);
        return item;
    }
    int size() const { return count; }
    bool empty() const{ return count == 0; }
    //insert
private:
    int *items;
    int count;
    
    void shiftDown(int i){
        while(LEFTNODE(i) < count){
            int j = LEFTNODE(i);
            if(RIGHTNODE(i) < count && items[j] < items[RIGHTNODE(i)])
                j = RIGHTNODE(i);
            if(items[i] >= items[j]) break;
            swap(items[i], items[j]);
            i = j;
        }
    }
    void shiftUp(int i){
        while(i > 0 && items[i] > items[PARENTNODE(i)]){
            swap(items[i], items[PARENTNODE(i)]);
            i = PARENTNODE(i);
        }
    }
};
class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here
        vector<int> top;
        if(nums.size() < k) return top;
        MaxHeap heap(nums);
        for(int i = 0; i < k && !heap.empty(); i++){
            top.push_back(heap.extractMax());
        }
        return top;
    }
};
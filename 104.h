/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
#define LEFTNODE(i)   ((i) * 2 + 1)
#define RIGHTNODE(i)  ((i) * 2 + 2)
#define PARENTNODE(i) ((i) > 0 ? (((i) - 1) / 2) : -1)

// class MinHeap
class MinHeap{
public:
    MinHeap(const vector<ListNode*> &arr){
        //copy(arr.begin(), arr.end(), back_inserter(array)); 
        count = arr.size();
        array = new ListNode*[count];
        copy(arr.begin(), arr.end(), array); 
        int i = PARENTNODE(count - 1);
        while(i >= 0){
            shiftDown(i);
            i--;
        }
    }
    ~MinHeap(){
        if(array) delete[] array;
    }
    int size() const { return count; }
    bool empty() const { return count == 0; }
    ListNode* extractMin(){
        ListNode* r = array[0];
        swap(array[0], array[count-1]);
        --count;
        shiftDown(0);
        return r;
    }
    
    void insert(ListNode* r){
        array[count] = r;
        ++count;
        shiftUp(count - 1);
    }
private:
    ListNode** array;
    int count;
    void shiftDown(int i){
        while(LEFTNODE(i) < count){
            int j = LEFTNODE(i);
            if(RIGHTNODE(i) < count && array[j]->val > array[RIGHTNODE(i)]->val){
                j = RIGHTNODE(i);
            }
            if(array[i]->val < array[j]->val) break;  // !!
            swap(array[i], array[j]);
            cout << array[i]->val << " " << array[j]->val << endl;
            i = j;
        }
    }
    void shiftUp(int i){
        while(i > 0 && array[PARENTNODE(i)]->val > array[i]->val){
            swap(array[PARENTNODE(i)], array[i]);
            i = PARENTNODE(i);
        }
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        // ListNode *head = nullptr;
        // for(int i = 0; i < lists.size(); i++){
        //     head = merge(head, lists[i]);
        // }
        // return head;
        ListNode dummyhead(-1);
        ListNode *head = &dummyhead;
        vector<ListNode*> arr;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] == nullptr) continue;
            arr.push_back(lists[i]);
        }
        MinHeap heap(arr);
        while(!heap.empty()){
            ListNode* node = heap.extractMin();
            head->next = node;
            head = head->next;
            
            if(node->next != nullptr){
                heap.insert(node->next);
            }
        }
        head->next = nullptr;
        return dummyhead.next;
    }
    ListNode *merge(ListNode *list1, ListNode *list2){
        ListNode dummy(0);
        ListNode *dummyhead = &dummy;
        
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                dummyhead->next = list1;
                dummyhead = list1;
                list1 = list1->next;
            }
            else{
                dummyhead->next = list2;
                dummyhead = list2;
                list2 = list2->next;
            }
        }
        
        if(list1) dummyhead->next = list1;
        else dummyhead->next = list2;
        return dummy.next;
    }
};



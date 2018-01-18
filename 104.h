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
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode *head = nullptr;
        for(int i = 0; i < lists.size(); i++){
            head = merge(head, lists[i]);
        }
        return head;
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



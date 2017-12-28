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
    /*
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode * insertionSortList(ListNode * head) {
        // write your code here
        ListNode *array_index = head;
        while(array_index != nullptr){
            ListNode *array_begin = head;
            while(array_begin != nullptr && array_begin != array_index){
                if(array_begin->val > array_index->val){
                    swap(array_begin->val, array_index->val);
                }
                array_begin = array_begin->next;
            }
            array_index = array_index->next;
        }
        return head;
    }
};
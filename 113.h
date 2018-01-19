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
     * @param head: head is the head of the linked list
     * @return: head of the linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        // write your code here
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummyhead(0);
        ListNode *cur = &dummyhead;

        while(head != nullptr){
            if(head->next != nullptr && head->next->val == head->val){
                int val = head->val;
                while(head != nullptr && head->val == val){
                    head = head->next;
                }
                continue;
            }
            else{
                cur->next = head;
                cur = head;
            }
            head = head->next;
        }
        cur->next = nullptr;
        return dummyhead.next;
    }
};
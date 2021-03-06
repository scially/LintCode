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
     * @return: head of linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        // write your code here
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummyhead(0);
        dummyhead.next = head;
        ListNode *cur = dummyhead.next;

        int val = head->val;
        while(head->next != nullptr){
            head = head->next;
            if(head->val != val){
                cur->next = head;
                cur = head;
                val = head->val;
            }
        }
        cur->next = nullptr;
        return dummyhead.next;
    }
};
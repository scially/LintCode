
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
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        // write your code here
        ListNode dummyhead(0);
        dummyhead.next = head;
        
        ListNode *slow = &dummyhead;
        ListNode *fast = head;
        int k = 0;
        while(k++ < n){
            fast = fast->next;
        }
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyhead.next;
    }
};
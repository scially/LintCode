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
     * @param head: The head of linked list.
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        // write your code here
        if(head == nullptr || head->next == nullptr) return;

        // find midnight node
        ListNode *fast = head, *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;
        // reverse
        mid = reverseList(mid);
        // merge two list
        ListNode *next;
        while(mid != nullptr){
            next = head->next;
            head->next = mid;
            mid = mid->next;
            head->next->next = next;
            head = next;
            //mid = mid->next;
        }
        //mid->next = nullptr;
        
    }
    
    ListNode *reverseList(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *next = head;
        while(next != nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
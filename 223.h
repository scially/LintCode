/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        if(head == nullptr) return true;
        // write your code here
        ListNode *slow = head, *fast = head;
        while(slow->next != nullptr && slow->next->next != nullptr){
            slow = slow->next->next;
            fast = fast->next;
        }
        ListNode *right = reverseList(fast->next);
        fast->next = nullptr;
        ListNode *left = head;
        
        while(right != nullptr){
            if(right->val != left->val)
                return false;
            right = right->next;
            left = left->next;
        }
        return true;
    }
    ListNode *reverseList(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *next = head;
        while(head != nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
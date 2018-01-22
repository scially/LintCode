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
     * @param head: a ListNode
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        // write your code here
        if(head == nullptr || head->next == nullptr) return head;
        ListNode dummyhead(0);
        ListNode *cur = &dummyhead;
        
        while(head != nullptr && head->next != nullptr){
            ListNode *next = head->next->next;
            ListNode *node = swap(head);
            cur->next = node;
            cur = node->next;
            head = next;
        }
        return dummyhead.next;
    }
    // swap node and node->next
    ListNode *swap(ListNode *node){
        ListNode *next = node->next;
        node->next = next->next;
        next->next = node;
        return next;
    }
};

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
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
        // write your code here
        if(head == nullptr) return head;
        ListNode dummyhead(0);
        ListNode *cur = &dummyhead;
        while(head != nullptr){
            if(head->val != val){
                cur->next = head;
                cur = head;
            }
            head = head->next;
        }
        cur->next = nullptr;
        return dummyhead.next;
    }
};
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
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode * nthToLast(ListNode * head, int n) {
        // write your code here
        if(head == nullptr) return head;
        
        ListNode *dummyhead = head;
        int length = 0;
        while(dummyhead != nullptr){
            length++;
            dummyhead = dummyhead->next;
        }
        
        for(int i = 0; i < length - n; i++){
            head = head->next;
        }
        return head;
    }
};
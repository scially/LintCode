/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: ListNode head is the head of the linked list 
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        // write your code here
        ListNode *_head = head, *head_aux = head;
        ListNode *prev = nullptr, *next, *mprev = nullptr;
        int i = 1;
        
        for(; i < m; i++){ //翻转链表的前一个结点
            mprev = head;
            head = head->next;
        }
        head_aux = head;
        
        for(; i <= n; i++){ //翻转链表的后一个结点
            prev = head_aux;
            head_aux = head_aux->next;
        }

        prev = prev->next;
        //翻转
        while(m <= n){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            m++;
        }
        
        if(!mprev) return prev;
        mprev->next = prev;
        return _head;
    }
};
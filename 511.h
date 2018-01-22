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
     * @param v1: An integer
     * @param v2: An integer
     * @return: a new head of singly-linked list
     */
    ListNode * swapNodes(ListNode * head, int v1, int v2) {
        // write your code here
        if(head == nullptr) return head;
        ListNode dummyhead(0);
        dummyhead.next = head;
        ListNode *cur = &dummyhead;
        
        ListNode *n1 = nullptr, *n2 = nullptr;
        while(cur->next != nullptr){
            if(cur->next->val == v1)
                n1 = cur;
            else if(cur->next->val == v2)
                n2 = cur;
            cur = cur->next;
        }
        if(n1 == nullptr || n2 == nullptr) return head;
        
        //n1 n2分别是v1 和 v2的前一个节点
        // n1 n2可能相邻
        ListNode *node2 = n2->next, *node1 = n1->next,*next;
        if(n1->next == n2){
            n1->next = node2;
            next = node2->next;
            node2->next = node1;
            node1->next = next;
        }
        else if(n2->next == n1){
            n2->next = node1;
            next = node1->next;
            node1->next = node2;
            node2->next = next;
        }
        else{
            next = node1->next;
            n2->next = node1;
            node1->next = node2->next;
            n1->next = node2;
            node2->next = next;    
        }
        

        return dummyhead.next;
    }
};
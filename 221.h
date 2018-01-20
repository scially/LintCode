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
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
    ListNode * addLists2(ListNode * l1, ListNode * l2) {
        // write your code here
        ListNode dummyhead(0);
        ListNode *cur = &dummyhead;
        ListNode *l1r = reverseList(l1);
        ListNode *l2r = reverseList(l2);
        
        int add = 0;
        while(l1r != nullptr && l2r != nullptr){
            int sum = l1r->val + l2r->val + add;
            add = sum / 10;
            sum = sum - add * 10;
            ListNode *next = new ListNode(sum);
            cur->next = next;
            cur = next;
            
            l1r = l1r->next;
            l2r = l2r->next;
        }
        ListNode *rem = l1r ? l1r : l2r;
        while(rem != nullptr){
            int sum = rem->val + add;
            add = sum / 10;
            sum = sum - add*10;
            ListNode *next = new ListNode(sum);
            cur->next = next;
            cur = next;
            
            rem = rem->next;
        }
        if(add){ // add = 1
            ListNode *next = new ListNode(add);
            cur->next = next;
            cur = next;
        }
        cur->next = nullptr;
        
        return reverseList(dummyhead.next);
    }
    ListNode *reverseList(ListNode *head){
        ListNode *prev = nullptr, *next;
        while(head != nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
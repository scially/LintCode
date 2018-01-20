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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        // write your code here
        ListNode dummyhead(0);
        ListNode *cur = &dummyhead;
        
        int add = 0;
        while(l1 != nullptr && l2!= nullptr){
            int val = l1->val + l2->val + add;
            add = val / 10;
            val = val - add * 10;
            cur->next = new ListNode(val);
            cur = cur->next;
            l1= l1->next;
            l2 = l2->next;
        }
        
        ListNode *lst = l1 ? l1 : l2;
        while(lst != nullptr){
            int val = lst->val + add;
            add = val /10;
            val = val - add*10;
            cur->next = new ListNode(val);
            cur = cur->next;
            lst = lst->next;
        }
        if(add){
            cur->next = new ListNode(add);
        }
        return dummyhead.next;
    }
};
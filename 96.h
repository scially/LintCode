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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        
        // qsort partition error
        // ListNode *dummy = new ListNode(-1);
        // dummy->next = head;
        
        // ListNode *prev = dummy;
        // ListNode *curt = dummy->next;
        // while(curt != nullptr){
        //     if(curt->val < x){
        //         prev = prev->next;
        //         swap(prev->val, curt->val);
        //     }
        //     curt = curt->next;
        // }
        
        // return dummy->next;
        
        
        // ListNode *dummyleft = new ListNode(0), *dummyright = new ListNode(0);
        // ListNode *_dummyleft = dummyleft, *_dummyright = dummyright;
        // while(head != nullptr){
        //     if(head->val < x){
        //         _dummyleft->next = head;
        //         _dummyleft = head;
        //     }
        //     else{
        //         _dummyright->next = head;
        //         _dummyright = head;
        //     }
        //     head = head->next;
        // }
        // _dummyright->next = nullptr; //防止链表死循环
        // _dummyleft->next = dummyright->next;
        // return dummyleft->next;

        // fix memory bugs
        ListNode dummyleft(0), dummyright(0);
        ListNode *_dummyleft = &dummyleft, *_dummyright = &dummyright;
        while(head != nullptr){
            if(head->val < x){
                _dummyleft->next = head;
                _dummyleft = head;
            }
            else{
                _dummyright->next = head;
                _dummyright = head;
            }
            head = head->next;
        }
        _dummyright->next = nullptr; //防止链表死循环
        _dummyleft->next = dummyright.next;
        return dummyleft.next;
    }
};
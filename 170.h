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
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
        // write your code here
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *left = head, *right;
        int list_length = 0;
        while(head != nullptr) {
            head = head->next;
            ++list_length;
        }
        k %= list_length; cout << k <<endl;
        head = left;
        if(k == 0) return head;
        
        for(int i = 1; i < list_length - k; i++){
            head = head->next;
        }
        right = head->next;
        head->next = nullptr;
        
        ListNode *dummyright = right;
        while(dummyright->next != nullptr)
            dummyright = dummyright->next;
        dummyright->next = left;
        return right;
    }
};
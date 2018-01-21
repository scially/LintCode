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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        // write your code here
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode *dummyheadA = headA;
        while(dummyheadA->next != nullptr)
            dummyheadA = dummyheadA->next;
        dummyheadA->next = headB;
        
        //现在问题归结为寻找链表环
        // 1是否有环
        ListNode *fast = headA, *slow = headA;
        bool flag = false;
        while(fast != nullptr && fast->next != nullptr && !flag){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) flag = true;
        }
        // 无环，即没有交叉结点
        if(!flag) return nullptr;
        
        ListNode *start = headA;
        while(start != slow){
            start = start->next;
            slow = slow->next;
        }
        return slow;
    }
};
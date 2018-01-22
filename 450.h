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
     * @param k: An integer
     * @return: a ListNode
     */
    ListNode * reverseKGroup(ListNode * head, int k) {
        // write your code here
        if(head == nullptr) return head;
        ListNode dummyhead(0);
        ListNode *cur = &dummyhead;
        ListNode *slow = head, *fast = head, *next;
        while(fast != nullptr){
            for(int i = 1; i < k && fast != nullptr; i++)
                fast = fast->next;
            if(fast == nullptr){
                // 最后剩余的不需要翻转
                cur->next = slow;
                break;
            }
            next = fast->next;
            fast->next = nullptr;
            // 翻转从slow到fast的节点
            cur->next = reverseList(slow);
            
            // 将slow和fast向前推进
            cur = slow;
            slow = fast = next;
        }
        return dummyhead.next;
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
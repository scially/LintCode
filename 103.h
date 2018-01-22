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
     * @return: The node where the cycle begins. if there is no cycle, return null
     */
    ListNode * detectCycle(ListNode * head) {
        // write your code here
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        bool flag = false;
        // 1判断是否有环
        ListNode *fast = head, *slow = head;
        while(fast != nullptr && fast->next != nullptr && !flag){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) flag = true;
        }
        //cout << boolalpha  << flag << endl;
        // 没有环
        if(!flag) return nullptr;
        ListNode *start = head;
        while(start != slow){
            slow = slow->next;
            start = start->next;
        }
        return start;
    }
};
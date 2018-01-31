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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode * sortedListToBST(ListNode * head) {
        // write your code here
        if(head == nullptr) return (TreeNode*)(head);
        // 当链表中仅有一个结点时，可直接返回
        if(head->next == nullptr) return new TreeNode(head->val);
        ListNode *node = mid(head);

        ListNode *mid = node->next;
        node->next = nullptr;
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right= sortedListToBST(mid->next);
        return root;
    }
    ListNode *mid(ListNode *head){
        if(head == nullptr) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
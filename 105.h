/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode dummyhead(0);
        RandomListNode *cur = &dummyhead;
        RandomListNode *tmp = head;
        while(tmp != nullptr){
            cur->next = new RandomListNode(tmp->label);
            cur = cur->next;
            m[tmp] = cur;
            tmp = tmp->next;
        }
        
        tmp = head;
        while(tmp != nullptr){
            m[tmp]->random = m[tmp->random];
            tmp = tmp->next;
        }
        return dummyhead.next;
    }
};
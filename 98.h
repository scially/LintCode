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
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        
        // 链表快排对于第一个要交换的数不好处理，单单只选择第一个可能退化为o(n2)
        // 对于链表来说，归并排序容易些
        //qsort(head, nullptr);
        //return head;
        
        return mergesort(head);
    }
    /*****************************qsort***********************************/
    // qsort [head, end)
    void qsort(ListNode *head, ListNode *end){
        if(head == end) return;
        if(head->next == end) return;
        ListNode *p = __partition(head, end);
        qsort(head, p);
        qsort(p->next, end);
    }
    
    // qsort parition[head, end)
    ListNode* __partition(ListNode *head, ListNode *end){
        int v = head->val;
        ListNode *p = head, *dummyhead = head;
        dummyhead = dummyhead->next;
        while(dummyhead != end){
            if(dummyhead->val <= v){
                p = p->next;
                swap(p->val, dummyhead->val);
            }
            dummyhead = dummyhead->next;
        }
        swap(head->val, p->val);
        return p;
    }
    
    /*****************************merge sort*****************************/
    // merge sort[head, end)
    ListNode* mergesort(ListNode *head){
        if( head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = findmidNode(head);
        ListNode *mid = dummy->next;
        dummy->next = nullptr;
        head = mergesort(head);
        mid = mergesort(mid);
        return merge(head, mid);
    }
    
    // find merge mid node[head, end)
    ListNode *findmidNode(ListNode *head){
        ListNode *fastnode = head, *slownode = head;
        while(fastnode->next != nullptr && fastnode->next->next != nullptr){
            slownode = slownode->next;
            fastnode = fastnode->next->next;
        }
        return slownode;
    }
    
    // verson 1
    // ListNode* merge(ListNode *head, ListNode *mid){
    //     ListNode auxhead(-1);
    //     auxhead.next = head;
    //     ListNode *dummyhead = &auxhead;
        
    //     ListNode *dummymid = mid;
    //     while(head != nullptr || dummymid != nullptr){
    //         if(head == nullptr){
    //             dummyhead->next = dummymid;
    //             dummyhead = dummymid;
    //             dummymid = dummymid->next;
    //         }
    //         else if( dummymid == nullptr){
    //             dummyhead->next = head;
    //             dummyhead = head;
    //             head = head->next;
    //         }
    //         else if(head->val < dummymid->val){
    //             dummyhead->next = head;
    //             dummyhead = head;
    //             head = head->next;
    //         }
    //         else{
    //             dummyhead->next = dummymid;
    //             dummyhead = dummymid;
    //             dummymid = dummymid->next;
    //         }
    //     }
    //     return auxhead.next;
    // }
    
    // verson 2
    ListNode* merge(ListNode *head, ListNode *mid){
        ListNode auxhead(-1);
        auxhead.next = head;
        ListNode *dummyhead = &auxhead;
        
        ListNode *dummymid = mid;
        while(head != nullptr && dummymid != nullptr){
            if(head->val <= dummymid->val){
                dummyhead->next = head;
                dummyhead = head;
                head = head->next;
            }
            else{
                dummyhead->next = dummymid;
                dummyhead = dummymid;
                dummymid = dummymid->next;
            }
        }
        if(head == nullptr) dummyhead->next = dummymid;
        else dummyhead->next = head;
        return auxhead.next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 找环的起点，还是用快慢指针，但是分别记录快慢指针走过的距离，相遇的时候，快指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* h1 = head;
        ListNode* h2 = head;
        while(h2 != NULL && h2->next != NULL) {
            h1 = h1->next;
            h2 = h2->next->next;
            if(h1 == h2) {
                while(h1 != head) {
                    h1 = h1->next;
                    head = head->next;
                }
                return h1;
            }
        }
        return NULL;
    }
};

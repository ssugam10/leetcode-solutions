/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *c = new ListNode(-1);
        c->next = head;
        
        ListNode *temp = c;
        ListNode *f1;
        while(temp && temp->next){
            f1 = temp->next;
            ListNode *f2 = f1->next;
            if(!f2) break;
            f1->next = f2->next;
            temp->next = f2;
            f2->next = f1;
            temp = temp->next->next;
        }
        
        return c->next;
    }
};
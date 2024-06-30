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
public: //This method has SC = O(1), and TC = O(m+n) 
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode *c = new ListNode(-1);
        ListNode *temp = c;
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                temp->next = a;
                a = a->next;
                temp = temp->next;
            }
            else{
                temp->next = b;
                b = b->next;
                temp = temp->next;
            }
        }
        if(a == NULL){
            temp->next = b;
        }
        else{
            temp->next = a;
        }
        return c->next;
    }
};
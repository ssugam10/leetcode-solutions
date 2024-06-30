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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next == NULL)    return head;
        ListNode *lo = new ListNode(-1);    //lo is the LL of smaller members
        ListNode *tempLo = lo;
        ListNode *hi = new ListNode(-2);    //hi is the LL of bigger members
        ListNode *tempHi = hi;
        ListNode *temp = head;
        while(temp!=NULL){
            if(temp->val<x){
                tempLo->next = temp;
                tempLo = tempLo->next;
                temp = temp->next;
            }
            else{
                tempHi->next = temp;
                tempHi = tempHi->next;
                temp = temp->next;
            }
        }
        tempHi->next = NULL;    //The last element may be connected to a smaller value
        tempLo->next = hi->next;
        return lo->next;
    }
};
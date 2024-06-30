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
ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL)    return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *Next = NULL;
        while(curr){
            Next = curr->next;  
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Now slow is at left middle/middle

        ListNode *b= reverseList(slow->next);
        slow->next = NULL;
        ListNode *temp = head;
        ListNode *temp2 = b;
        ListNode *c = new ListNode(-1);
        ListNode *tempC = c;

        while(temp && temp2){
            tempC->next = temp;
            tempC = tempC->next;
            temp = temp->next;

            tempC->next = temp2;
            tempC = tempC->next;
            temp2 = temp2->next;
        }
       
        tempC->next = temp;
        head = c->next;
    }
};
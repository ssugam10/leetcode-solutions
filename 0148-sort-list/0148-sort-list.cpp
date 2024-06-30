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
    ListNode *merge(ListNode *a, ListNode *b){
        ListNode *c = new ListNode(-1); //Farzi start node
        ListNode *tempC = c;
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                tempC->next = a;
                a = a->next;
                tempC = tempC->next;
            }
            else{
                tempC->next = b;
                b = b->next;
                tempC = tempC->next;
            }
        }
        if(a==NULL)   tempC->next = b;
        else    tempC->next = a;
        return c->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        //Firstly we need to calculate the middle of the linked list
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            //fast->next->next because we need to find the left middle incase of even number elements
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *a = head;
        ListNode *b = slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode *c = merge(a,b);
        return c;
    }
};
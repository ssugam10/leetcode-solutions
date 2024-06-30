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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL)    return head;
        ListNode *fhalf = new ListNode(-1); //contains even indexed ele
        ListNode *shalf = new ListNode(-2); //contains odd indexed ele
        ListNode *temp = head;
        ListNode *tempf = fhalf;
        ListNode *temps = shalf;
        while(temp!=NULL && temp->next!=NULL){
            //temp will only jump on even indices considering 0 as even number
            tempf->next = temp;
            temps->next = temp->next;
            temp = temp->next->next;
            tempf = tempf->next;
            temps = temps->next;
        }
        if(temp!=NULL){
            tempf->next = temp;
            tempf = tempf->next;
        }  
        temps->next = NULL;
        tempf->next = shalf->next;
        return fhalf->next;
    }
};
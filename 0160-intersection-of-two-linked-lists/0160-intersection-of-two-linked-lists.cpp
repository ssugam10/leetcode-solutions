/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        int m = 0;
        while(tempA!=NULL){
            tempA = tempA->next;
            m++;
        }
        int n = 0;
        while(tempB!=NULL){
            tempB = tempB->next;
            n++;
        }

        tempA = headA;
        tempB = headB;
        if(m>n){
            int diff = m-n;
            while(diff--){
                tempA = tempA->next;
            }
        }
        else{
            int diff = n-m;
            while(diff--){
                tempB = tempB->next;
            }
        }

        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};
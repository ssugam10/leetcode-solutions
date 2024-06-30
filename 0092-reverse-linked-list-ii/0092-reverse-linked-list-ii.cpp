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
ListNode* reverseList(ListNode* head, ListNode *checkPoint) {
        if(head==NULL || head->next == NULL)    return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *Next = NULL;
        while(curr!=checkPoint){
            Next = curr->next;  
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode *leftNode=head;
        ListNode *rightNode = head; 
        for(int i = 1; i<=right; i++){
            if(i<left-1)  leftNode = leftNode->next;
            rightNode = rightNode->next;
        }   
        if(leftNode == head && left==1){
            leftNode = reverseList(head,rightNode);
            head = leftNode;
        }    
        else leftNode->next = reverseList(leftNode->next, rightNode);
        ListNode *temp = leftNode;
        while(temp->next!=NULL) temp = temp->next;
        temp->next = rightNode;
        return head;
    }
};
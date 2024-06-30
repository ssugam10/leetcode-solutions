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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode *temp = head;
        int gap = 1;
        while(temp && temp->next){
            int remLen = 0;
            ListNode *t = temp->next;
            for(int i = 1; i<=gap+1 && t; i++){
                t = t->next;
                remLen++;
            }
            if(remLen < gap+1)  gap = remLen - 1;
            if(gap%2!=0)    reverseBetween(temp,2,2+gap);
            gap++;
            for(int i = 1; temp!=NULL && i<=gap; i++) temp = temp->next;
        }
        return head;
    }
    
};
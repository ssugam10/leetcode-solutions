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
    ListNode *reverseList(ListNode *head, ListNode *checkPoint){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *ahead = NULL;
        while(curr!=checkPoint){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *fixedPtr = new ListNode(-1);
        ListNode *slow = fixedPtr;
        slow->next = head;
        ListNode *fast = head;
        int count = 0;
        while(fast){
            if(count==k){
                ListNode *newHead = reverseList(slow->next,fast);
                slow->next = newHead;
                ListNode *temp=newHead;
                while(temp->next) temp = temp->next;
                slow = temp;
                slow->next = fast;
                count = 0;
                //continue;
            }
            if(fast)    fast = fast->next;
            count++;
        }
        if(fast==NULL && count==k){
            ListNode *newHead = reverseList(slow->next,fast);
            slow->next = newHead;
            ListNode *temp=newHead;
            while(temp->next) temp = temp->next;
            slow = temp;
            slow->next = fast;
        }
        return fixedPtr->next;
    }
};

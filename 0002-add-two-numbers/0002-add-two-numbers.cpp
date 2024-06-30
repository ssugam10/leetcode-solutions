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
    string calculateNum(ListNode *temp, string num){
        if(temp == NULL)  return num;
        return calculateNum(temp->next, to_string(temp->val) + num);
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1 = calculateNum(l1, "");
        string num2 = calculateNum(l2, "");

        int carry = 0;
        ListNode *head = nullptr;
        ListNode *prevNode = nullptr;

        for(int i = num1.length() - 1, j = num2.length() - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
            int x = (i >= 0) ? (num1[i] - '0') : 0;
            int y = (j >= 0) ? (num2[j] - '0') : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            ListNode *newNode = new ListNode(sum % 10);
            if (head == nullptr) {
                head = newNode;
            } else {
                prevNode->next = newNode;
            }
            prevNode = newNode;
        }

        return head;
    }
};

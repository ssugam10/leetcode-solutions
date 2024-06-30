class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp = head;
        int size = 0;
        while(temp){
            temp = temp->next;
            size++;
        } 
        int remainder = size%k; //starting wale aise parts jinki length ek zyada hai
        int num = size/k - 1;  //num decides the even length of the linked list
        vector<ListNode*> lists;
        temp = head;
      
        ListNode *newHead = head;
        while(temp){
            lists.push_back(newHead);
            for(int i = 0; i<num ; i++)    temp = temp->next;
            if(remainder && size>k){
                temp = temp->next;
                remainder--;
            }
            newHead = temp->next;
            temp->next = NULL;
            temp = newHead;
        }

        if(k > size){
            int iterationsLeft = k-size;
            while(iterationsLeft--){
                lists.push_back(NULL);
            }
        }
        return lists;
    }
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //Calculate size of the linked list
        if(head == NULL || head->next == NULL)  return head;
        int size = 0;
        ListNode *temp = head;
        ListNode *tail;
        while(temp!=NULL){
            if(temp->next==NULL)    tail = temp;
            temp = temp->next;
            size++;
        }
        //We now have tail at required position, we need to get temp at it's position now
        //we need to take temp (size-k-1) positions forward from head, we want it on (size-k-1)th index
        k = k % size;
        
        temp = head;
        for(int i = 0; i<size-k-1; i++)    temp = temp->next;
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;

        /*
        Slow and fast pointer approach isn't good since if we dont know the length of LL, it will return 
        error since k can be > size of LL which will cause error since the for loop of fast makes it 
        run 'k' positions in the start which leads to null ptr exception, this approach is optimal incase
        k< size of LL.. Hence we need to calculate the size of LL to solve this problem
        */
    }
};
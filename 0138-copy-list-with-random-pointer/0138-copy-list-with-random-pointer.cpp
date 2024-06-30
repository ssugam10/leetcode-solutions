/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //step 1
        Node *dummy = new Node(-1);
        Node *tempd = dummy;
        Node *temp = head;
        while(temp){
            Node *a = new Node(temp->val);
            tempd->next = a;
            tempd = tempd->next;
            temp = temp->next;
        }
        Node *b = dummy->next;  //created a deep copy without the random pointers
        Node *newList = b;

        unordered_map<Node*, Node*> mp;
        Node *a = head;
        while(a){
            mp[a] = b;
            a = a->next;
            b = b->next;
        }

        for(auto ele : mp){
            if((ele.first)->random)    (ele.second)->random = mp[(ele.first)->random];
        }

        return newList;    
    }

    
        
};
class Node{
    public:
    Node *left;
    Node *right;
    Node(){
        this->left = this->right = NULL;
    }
};

class Solution {
public: 
    //compares incoming value with exisiting inserted data in trie
    int maxXorPair(Node *head, int value){  
        int curr_xor = 0;
        Node *curr = head;
        for(int i = 31; i>=0; i--){
            int bit = ((value >> i) & 1);
            if(bit == 0){
                if(curr->right){
                    curr = curr->right;
                    curr_xor += (1 << i);
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->left){
                    curr = curr->left;
                    curr_xor += (1<<i);
                }
                else{
                    curr = curr->right;
                }
            }
        }

        return curr_xor;
    }

    void insert(Node *head, int value){
        Node *curr = head;
        for(int i = 31; i>=0; i--){
            int bit = ((value >> i) & 1);
            if(bit == 0){
                if(!curr->left){
                    curr->left = new Node();
                }
                curr = curr->left;
            }
            else{
                if(!curr->right){
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        int xorValue = 0;
        Node *root = new Node();
        for(int i = 0; i<nums.size(); i++){
            insert(root,nums[i]);
            if(i>0){
                xorValue = max(xorValue, maxXorPair(root,nums[i]));
            }
        }

        return xorValue;
    }
};
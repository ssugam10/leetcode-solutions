/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {  
        if(!root)   return;
        TreeNode *curr = root;
        while(curr){
            if(curr->left){
                TreeNode *r = curr->right;  //save the right
                
                curr->right = curr->left;
                
                TreeNode *pred = curr->left;
                while(pred->right)   pred = pred->right;
                
                pred->right = r;    //linking 
                
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        
        TreeNode *temp = root;
        while(temp->right){
            temp->left = NULL;
            temp = temp->right;
        }
    }
};
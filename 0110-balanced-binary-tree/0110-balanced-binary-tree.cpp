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
    bool flag;
    
    int f(TreeNode *root){
        if(!root || !flag)   return 0;
        
        int left = f(root->left);
        int right = f(root->right);
        
        if(abs(left - right) > 1){
            flag = false;
        }
        
        return max(left,right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        flag = true;  
        
        f(root);
        
        return flag;
    }
};
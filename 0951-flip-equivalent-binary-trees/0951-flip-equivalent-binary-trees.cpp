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
    bool f(TreeNode *first, TreeNode *second){
        
        if(!first && !second)   return true;
        
        if(!first || !second)   return false;
        
        if(first->val != second->val)   return false;
        
        return ((f(first->left,second->left) && f(first->right, second->right)) || f(first->left,second->right) && f(first->right,second->left) );
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return f(root1,root2);
    }
};
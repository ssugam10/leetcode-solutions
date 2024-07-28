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
    bool f(TreeNode *l, TreeNode *r){
        
        if(l == NULL && r == NULL)  return true;
        
        if(l == NULL || r == NULL)  return false;
        
        if(l->val != r->val)    return false;
        
        bool ans = true;
        
        ans = ans && f(l->right, r->left);
        
        ans = ans && f(l->left, r->right);
        
        return ans;
    }
    
    bool isSymmetric(TreeNode* root) {
        return f(root->left, root->right);
    }
};
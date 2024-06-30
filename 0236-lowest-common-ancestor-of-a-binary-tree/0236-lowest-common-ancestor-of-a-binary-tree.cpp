/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode *root, TreeNode *target){
        if(!root)   return false;
        if(root==target)  return true;
        return find(root->left,target) || find(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(find(root->left,p) && find(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if(find(root->right,p) && find(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};
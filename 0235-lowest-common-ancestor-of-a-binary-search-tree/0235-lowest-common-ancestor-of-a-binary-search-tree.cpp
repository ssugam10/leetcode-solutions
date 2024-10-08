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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val  ||  root->val == q->val) return root;   //this and next line can be merged in else
        if((root->val < p->val && root->val > q->val) || (root->val > p->val && root->val < q->val))    return root;
        else if(root->val > p->val && root->val > q->val)   return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};
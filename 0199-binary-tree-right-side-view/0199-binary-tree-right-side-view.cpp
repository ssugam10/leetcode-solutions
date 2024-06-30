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
    int findLevels(TreeNode *root){
        if(!root)   return 0;
        return 1+max(findLevels(root->left),findLevels(root->right));
    }

    void preOrder(TreeNode *root, int level, vector<int>& ans){
        if(!root)   return;
        ans[level] = root->val;
        preOrder(root->left,level+1,ans);
        preOrder(root->right,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = findLevels(root);
        vector<int> ans(n,0);
        preOrder(root,0,ans);
        return ans;
    }


};
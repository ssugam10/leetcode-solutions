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
    unordered_map<TreeNode*, int> dp;   //stores the maximum path sum starting at a particular node from it till root
    int mx;
    
    int traverse(TreeNode *node){
        if(!node)   return 0;
        return dp[node] = max(max({traverse(node->left), traverse(node->right)}) + node->val,0); 
    }
    
    void dfs(TreeNode *node){
        if(!node)   return;
        mx = max({mx, dp[node->left] + dp[node->right] + node->val});
        dfs(node->left);
        dfs(node->right);
    }
    
    
    int maxPathSum(TreeNode* root) {
        dp[NULL] = 0;
        mx = INT_MIN;
        
        traverse(root);
        
        dfs(root);
        
        return mx;
    }
};
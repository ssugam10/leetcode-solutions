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
    //unordered_map<TreeNode*, int> dp;   //stores the maximum path sum starting at a particular node from it till root
    int mx;
    
    int traverse(TreeNode *node){
        if(!node)   return 0;
        int left = max(0,traverse(node->left));
        int right = max(0,traverse(node->right));
        
        mx = max({mx, left + node->val, right + node->val, node->val, left + right + node->val});
        
        return node->val + max(left, right);
    }
    
    // void dfs(TreeNode *node){
    //     if(!node)   return;
    //     mx = max({mx, dp[node->left] + dp[node->right] + node->val});
    //     dfs(node->left);
    //     dfs(node->right);
    // }
    
    int maxPathSum(TreeNode* root) {
        //dp[NULL] = 0;
        mx = INT_MIN;
        
        traverse(root);
        
        //dfs(root);
        
        return mx;
    }
};
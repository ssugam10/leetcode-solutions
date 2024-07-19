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
    unordered_map<TreeNode*,int> heights;
    
    unordered_map<int,int> ans; //stores the maximum height of tree without a particular node
    
    int findHeights(TreeNode *node){
        if(!node)   return 0;
        
        return heights[node] = 1 + max(findHeights(node->left),findHeights(node->right));
    }
    
    void dfs(TreeNode *node, int depth, int mx){
        if(!node)   return;
        ans[node->val] = mx;
        dfs(node->left, depth + 1, max(mx, heights[node->right] + depth));
        dfs(node->right, depth + 1, max(mx, heights[node->left] + depth));
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        heights.clear();
        ans.clear();
     
        findHeights(root);
        
        dfs(root,0,0);
        
        vector<int> result;
        for(int i = 0; i<queries.size(); i++){
            int node = queries[i];
            result.push_back(ans[node]);
        }
        
        return result;
    }
};
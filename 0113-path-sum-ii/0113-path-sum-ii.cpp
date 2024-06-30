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
    void findPaths(TreeNode *root, int target, vector<vector<int>>& ans, vector<int> elements){
        if(!root)   return;
        if(!root->left && !root->right){
            if(root->val == target){
                elements.push_back(root->val);
                ans.push_back(elements);
            }   
            return;
        }
        elements.push_back(root->val);
        findPaths(root->left,target-root->val,ans,elements);
        findPaths(root->right,target-root->val,ans,elements);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> elements;
        findPaths(root,targetSum,ans,elements);
        return ans;
    }
};
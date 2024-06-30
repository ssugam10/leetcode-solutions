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

    int findLevel(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(findLevel(root->left), findLevel(root->right));
    }

    void displaynthLevel(TreeNode *root, int currLevel, vector<vector<int>>& elements)
    {
        if (root == NULL)
            return;
        elements[currLevel].push_back(root->val);
        displaynthLevel(root->left, currLevel + 1,elements);  // left
        displaynthLevel(root->right, currLevel + 1,elements); // right
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = findLevel(root);
        vector<vector<int>> elements;
        vector<int> ele;
        for(int i = 1; i<=n ; i++){
            elements.push_back(ele);
        }
        displaynthLevel(root,0,elements);
        return elements;
    }
};
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
    void pathFinder(TreeNode *root, string path, vector<string>& paths){
        if(!root)   return;
        if (!root->left && !root->right) {
            paths.push_back(path+to_string(root->val));
            return;
        }
        pathFinder(root->left, path + to_string(root->val) + "->", paths);
        pathFinder(root->right, path + to_string(root->val) + "->", paths);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths; // Handle the case when the tree is empty
        pathFinder(root, "", paths);
        return paths; // Return the paths vector
    }
};

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
    int findLevel(TreeNode *root){
        if(root == NULL)    return 0;
        return 1 + max(findLevel(root->left),findLevel(root->right));
    }

    void helper(TreeNode *root,int &maxDia){
        if(root == NULL)    return;
        int dia = findLevel(root->left) + findLevel(root->right);
        maxDia = max(dia,maxDia);
        helper(root->left,maxDia);
        helper(root->right,maxDia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0; //reinitialize
        helper(root, maxDia);
        return maxDia;  
    }
};
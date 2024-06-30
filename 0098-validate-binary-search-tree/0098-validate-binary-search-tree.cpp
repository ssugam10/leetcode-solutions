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
    TreeNode *prev = NULL;
    bool flag = true;   

    void inorder(TreeNode *root){
        if(!root)   return;
        inorder(root->left);
        if(prev){
            if(root->val <= prev->val){
                flag = false;
                return;
            }
        }
        prev = root;
        inorder(root->right);
    }

    bool isValidBST(TreeNode* root){ 
        inorder(root);
        return flag;
    }
};
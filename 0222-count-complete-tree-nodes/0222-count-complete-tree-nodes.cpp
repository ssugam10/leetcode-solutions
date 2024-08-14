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
    int leftHeight(TreeNode *root){
        int ct = 1;
        while(root->left){
            root = root->left;
            ct++;
        }
        
        return ct;
    }
    
    int rightHeight(TreeNode *root){
        int ct = 1;
        while(root->right){
            root = root->right;
            ct++;
        }
        return ct;
    }
    
    //Counts the number of nodes in the subtree rooted at root
    int traverse(TreeNode *root){
        if(!root)   return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        //We can apply the full binary tree forumula
        if(lh == rh){
            return pow(2,lh) - 1;
        }
        
        return 1 + traverse(root->left) + traverse(root->right);
    }
    
    int countNodes(TreeNode* root) {
        return traverse(root);
    }
};
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
    TreeNode *iop(TreeNode *root){
        if(!root->left) return NULL;  
        TreeNode *pred = root->left;
        while(pred->right){
            pred = pred->right;
        }
        return pred;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        if(root->val == key){
            if(!root->left && !root->right){
                return NULL;
            }

            if(!root->left || !root->right){
                if(root->left)  return root->left;
                else return root->right;
            }

            //case with two children 
            TreeNode *pred = iop(root); //pred surely has <=1 children
            int value = pred->val;
            root->left = deleteNode(root->left,value);
            root->val = value;
            return root;
        }

        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }

        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};
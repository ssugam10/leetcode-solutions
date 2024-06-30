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
    void findPaths(TreeNode *root, long long target, int& count){
        if(!root)   return;
        if((long long)(root->val) == target){
            count++;
        } 
        findPaths(root->left,target-(long long)(root->val),count);
        findPaths(root->right,target-(long long)(root->val),count);
    }


    int pathSum(TreeNode* root, int targetSum) {    //to add the sums of every nodepath
        if(!root)   return 0;
        int count = 0;
        findPaths(root,(long long)(targetSum),count);
        count += (pathSum(root->left,targetSum) + pathSum(root->right,targetSum));
        return count;
    }
};
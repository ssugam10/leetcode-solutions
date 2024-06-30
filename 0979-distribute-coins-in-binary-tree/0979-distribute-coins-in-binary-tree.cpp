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
    int steps = 0;
    int f(TreeNode* node){
        if(!node)   return 0;

        int leftVal = f(node->left);
        int rightVal = f(node->right);

        steps += abs(leftVal) + abs(rightVal);

        return (node->val - 1 + leftVal + rightVal); 

    }

    int distributeCoins(TreeNode* root) {
        int ans = f(root);
        //cout<<ans;    //will always be 0
        return steps;
    }
};
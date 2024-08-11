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
    int ans;
    
    void mark(TreeNode *node, int k, int &cnt){
        if(!node || cnt > k)    return;
        
        mark(node->left, k, cnt);
        
        cnt++;
        
        if(cnt == k){
            ans = node->val;
            return;
        }
        
        mark(node->right,k,cnt);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        mark(root,k,count);
        
        return ans;
    }
};
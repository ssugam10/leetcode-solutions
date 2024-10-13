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
    unordered_map<TreeNode *, int> nodes;
    vector<int> sizes;
    
    int dfs(TreeNode *root){
        if(!root)   return 0;
        return nodes[root] = 1 + dfs(root->left) + dfs(root->right);
    }
    
    int traverse(TreeNode *root){
        if(!root)   return 0;
        
        int height = min(traverse(root->left), traverse(root->right)) + 1;
        
        if(nodes[root] == pow(2,height) - 1){
            sizes.push_back(nodes[root]);
            return height;
        }
        else{
            return 0;
        }
    }
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        
        traverse(root);
        
        sort(sizes.rbegin(),sizes.rend());
        
        if(k > sizes.size())    return -1;
        
        return sizes[k - 1];
    }
};
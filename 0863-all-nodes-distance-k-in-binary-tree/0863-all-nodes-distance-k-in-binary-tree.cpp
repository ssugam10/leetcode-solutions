/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*> parent;
    
    vector<int> nodes;
    
    void markParent(TreeNode *root){
        
        if(!root)   return;
        
        if(root->left){
            parent[root->left] = root;
            markParent(root->left);
        }
        
        if(root->right){
            parent[root->right] = root;
            markParent(root->right);
        }
    }
    
    void dfs(TreeNode *root, int dist, set<TreeNode*> &visited){
        
        if(!root)   return;
        
        visited.insert(root);
        
        if(dist == 0){
            nodes.push_back(root->val);
            return;
        }
        
        if(root->left && !visited.count(root->left)){
            dfs(root->left,dist - 1, visited);
        }
        
        if(root->right && !visited.count(root->right)){
            dfs(root->right,dist - 1, visited);
        }
        
        if(parent[root] && !visited.count(parent[root])){
            dfs(parent[root],dist - 1, visited);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent[root] = NULL;
        markParent(root);
        
        nodes.clear();
        set<TreeNode*> visited;
        dfs(target,k,visited);
        
        return nodes;
        
    }
};
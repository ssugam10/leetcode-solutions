#define ll long long int
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
    vector<int> depthVal;

    void bfs(queue<TreeNode *> &q){
        ll levelSum = 0;
        
        while(!q.empty()){
            ll sz = q.size();
            for(ll i = 0; i<sz; i++){
                TreeNode *node = q.front();
                q.pop();
                levelSum += (ll)node->val;
                
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            depthVal.push_back(levelSum);
            levelSum = 0;
        }
    }
    
    void traverse(TreeNode *root, ll depth){
        
        if(!root)   return;
        
        ll childSum = 0;
        
        if(root->left)  childSum += root->left->val;
        if(root->right) childSum += root->right->val;
        
        if(root->left){
            root->left->val = depthVal[depth] - childSum;
        }
        
        if(root->right){
            root->right->val = depthVal[depth] - childSum;
        }
        
        traverse(root->left,depth + 1);
        traverse(root->right, depth + 1);
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        bfs(q);
        
        // for(auto ele : depthVal){
        //     cout<<ele<<" ";
        // }
        
        root->val = 0;
        
        traverse(root,1);
        
        return root;
    }
};
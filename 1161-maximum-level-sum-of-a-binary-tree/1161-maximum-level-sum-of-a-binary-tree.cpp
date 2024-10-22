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
    ll bfs(queue<TreeNode *> &q){
        ll levelSum = 0;
        
        ll level = 1;
        ll mx = INT_MIN;
        ll mxLevel = 1;
        
        while(!q.empty()){
            ll sz = q.size();
            for(ll i = 0; i<sz; i++){
                TreeNode *node = q.front();
                q.pop();
                levelSum += (ll)node->val;
                
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            if(levelSum > mx){
                mx = levelSum;
                mxLevel = level;
            }
            
            levelSum = 0;
            level++;
        }
        
        return mxLevel;
    }
    
    int maxLevelSum(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        
        return bfs(q);
    }
};
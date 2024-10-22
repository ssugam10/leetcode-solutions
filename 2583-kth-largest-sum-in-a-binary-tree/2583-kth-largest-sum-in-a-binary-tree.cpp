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
    ll bfs(queue<TreeNode *> &q, int k){
        ll levelSum = 0;
        
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        
        while(!q.empty()){
            ll sz = q.size();
            for(ll i = 0; i<sz; i++){
                TreeNode *node = q.front();
                q.pop();
                levelSum += (ll)node->val;
                
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            pq.push(levelSum);
            levelSum = 0;
            
            if(pq.size() > k)   pq.pop();
        }
        
        if(pq.size() == k)  return pq.top();
        return -1;
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        
        return bfs(q,k);
    }
};
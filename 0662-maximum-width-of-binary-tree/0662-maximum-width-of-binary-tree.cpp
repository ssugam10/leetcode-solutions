/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll width = 0;
        queue<pair<TreeNode*, ll>> q;
        
        q.push({root, 0});
        q.push({NULL, -1});
        ll currRowStart = 0;
        ll currRowEnd = 0;
        ll start = -1;
        
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            ll idx = q.front().second;
            q.pop();
            
            if (idx == -1) {
                width = max(width, currRowEnd - currRowStart + 1);
                if (q.empty()) break;
                q.push({NULL, -1});
                currRowStart = LLONG_MAX;
                currRowEnd = LLONG_MIN;
                start = -1;
                continue;
            } else {
                currRowStart = min(currRowStart, idx);
                currRowEnd = max(currRowEnd, idx);
            }
            
            if(start == -1){
                start = idx;
            }
            
            if (node->left) {
                q.push({node->left, 2 * idx + 1 - start});
            }
            
            if (node->right) {
                q.push({node->right, 2 * idx + 2 - start});
            }
        }
        
        return width;
    }
};

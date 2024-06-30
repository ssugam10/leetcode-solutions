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
    void displaynthLevel(TreeNode *root, int currLevel, int n, vector<int>& elements)
    {
        if (root == NULL)
            return;
        if (currLevel == n)
        {
            elements.push_back(root->val);
            return; // This avoids going deeper in the tree for no reason 
        }
        displaynthLevel(root->left, currLevel + 1, n,  elements);  // left
        displaynthLevel(root->right, currLevel + 1, n, elements); // right
    }

    void nthLevelRev(TreeNode *root, int currLevel, int n, vector<int>& elements){
        if(!root)   return;
        if(currLevel == n){
            elements.push_back(root->val);
            return;
        }
        nthLevelRev(root->right,currLevel+1,n, elements);
        nthLevelRev(root->left,currLevel+1,n,elements);
    }

    int findLevel(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(findLevel(root->left), findLevel(root->right));
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> elements;
        int n = findLevel(root);
        for(int i = 1; i<=n ; i++){
            elements.clear();
            if(i%2!=0)  displaynthLevel(root,1,i,elements);
            else nthLevelRev(root,1,i,elements);
            ans.push_back(elements);
        }

        return ans;
    }
};
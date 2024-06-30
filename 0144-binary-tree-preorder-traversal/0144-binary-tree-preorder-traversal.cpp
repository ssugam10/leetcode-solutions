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
    void preOrder(TreeNode *root, vector<int>& elements)
    {
        stack<TreeNode*> st;
        if(root)    st.push(root);
        while (!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            elements.push_back(temp->val);
            if (temp->right)
                st.push(temp->right);
            if (temp->left)
                st.push(temp->left);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> elements;
        preOrder(root,elements);
        return elements;
    }
};
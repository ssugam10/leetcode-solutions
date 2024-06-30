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
    TreeNode *build(vector<int>& pre, int preLo, int preHi, vector<int>& in, int inLo, int inHi){
        if(preLo>preHi)    return NULL; 
        TreeNode *root = new TreeNode(pre[preLo]);
        if(preLo == preHi)   return root; 
        int i = inLo;
        while(i<=inHi){
            if(in[i]==pre[preLo])   break;
            i++;
        }
        //i is now at the index where root exists in the inorder array

        int leftCount = i - inLo;

        root->left = build(pre,preLo+1,preLo+leftCount,in,inLo,i-1);
        root->right = build(pre,preLo+leftCount+1,preHi,in,i+1,inHi);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};
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
    int maxLen;
    
    void traverse(TreeNode *node, int pathLength, bool isRight){
        if(!node)   return;
        
        maxLen = max(maxLen, pathLength);
        
        if(isRight){    //iska matlab tum is node pe right lekar aaye ho pichle node se
            traverse(node->left,pathLength+1,false);
            traverse(node->right,1,true);
        }
        else{
            traverse(node->right,pathLength + 1, true);
            traverse(node->left,1,false);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        maxLen = 0;
        traverse(root->left,1,false);
        traverse(root->right,1,true);
        return maxLen;
    }
};
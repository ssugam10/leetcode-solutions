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
    int n;
    
    vector<TreeNode *> f(int i, int j){
        
        if(i > j)   return {NULL};
        
        vector<TreeNode*> possibleTrees;
        for(int k = i; k<=j; k++){
            vector<TreeNode*> leftTree = f(i,k-1);
            vector<TreeNode*> rightTree = f(k+1,j);
            
            for(auto leftSubTree : leftTree){
                for(auto rightSubTree : rightTree){
                    TreeNode *root = new TreeNode(k);
                    root->left = leftSubTree;
                    root->right = rightSubTree;
                    possibleTrees.push_back(root);
                }
            }
        }
        
        return possibleTrees;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        this->n = n;
        
        return f(1,n);
    }
};
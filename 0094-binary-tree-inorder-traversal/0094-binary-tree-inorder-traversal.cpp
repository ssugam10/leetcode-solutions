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
class Solution {    //Morris Travaersal
public:
    void visit(TreeNode *node, vector<int>& ans){
        ans.push_back(node->val);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *curr = root;
        
        while(curr){
            if(curr->left){
                TreeNode *pred = curr->left;
                while(pred->right && pred->right!=curr)  pred = pred->right;
                
                if(!pred->right){    
                    pred->right = curr;
                    curr = curr->left;
                }
                
                if(pred->right==curr){
                    pred->right = NULL;
                    visit(curr,ans);
                    curr = curr->right;
                }
            }
            
            else{
                visit(curr,ans);
                curr = curr->right;
            }
        }
        
        return ans;
    }
};
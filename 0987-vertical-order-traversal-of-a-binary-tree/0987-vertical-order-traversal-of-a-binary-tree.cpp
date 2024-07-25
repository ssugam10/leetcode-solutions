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
    vector<vector<pair<int,int>>> vp;   // vector of cols where each cols contains node value and its row
    
    void f(TreeNode *node, int row, int col){
        if(!node)   return;
        vp[col + 1000].push_back({node->val, row});
        f(node->left,row + 1, col - 1);
        f(node->right, row + 1, col + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vp.clear();
        vp.resize(2000,{});
        
        f(root,0,0);
        
        for(int i = 0; i < 2000; i++){
            if(vp[i].size() == 0)   continue;
            
            sort(vp[i].begin(),vp[i].end(), [](auto p1, auto p2){
                if(p1.second == p2.second){
                    return p1.first < p2.first;
                }
                return p1.second < p2.second;
            });
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i<2000; i++){
            if(vp[i].size() == 0)   continue;
            
            vector<int> vec;
            for(int j = 0; j<vp[i].size(); j++){
                vec.push_back(vp[i][j].first);
            }
            
            ans.push_back(vec);
        }
        
        return ans;
    }
};
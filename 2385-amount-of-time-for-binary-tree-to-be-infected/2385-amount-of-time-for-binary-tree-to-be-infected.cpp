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
    TreeNode *startNode = NULL;

    void setParent(TreeNode *root, unordered_map<TreeNode*,TreeNode*>& parent){ //To map all nodes with the parent
        if(!root)   return;    
        if(root->left)  parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        setParent(root->left,parent);
        setParent(root->right,parent);
    }

    void findInfectedNode(TreeNode *root, int start){
        if(!root)   return;
        if(root->val == start){
            startNode = root;
            return;
        } 
        findInfectedNode(root->left,start);
        findInfectedNode(root->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        setParent(root,parent); //parents wala map ban gaya

        findInfectedNode(root,start);   //here we set the startNode to the address of the infected node
        
        queue<pair<TreeNode*, int>> q;  //each treenode is stored along with level
        unordered_set<TreeNode*> isInfected;    //the treenode stored here is infected

        q.push({startNode,0});
        isInfected.insert(startNode);

        int maxLevel = 0;   //will help to find the time in the end
        while(q.size()>0){
            TreeNode *node = (q.front()).first;
            int level = (q.front()).second;
            q.pop();
            if(node->left){
                if(isInfected.find(node->left)==isInfected.end()){
                    q.push({node->left,level+1});
                    isInfected.insert(node->left);
                }
            }  

            if(node->right){
                if(isInfected.find(node->right)==isInfected.end()){
                    q.push({node->right,level+1});
                    isInfected.insert(node->right);
                }
                
            } 

            if(parent[node]){
                if(isInfected.find(parent[node])==isInfected.end()){
                    q.push({parent[node],level+1});
                    isInfected.insert(parent[node]);
                }
                
            }    

            maxLevel = max(maxLevel,level);
        }

        return maxLevel;
    }
};
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    int first;
    TreeNode *start;
    
    void dfs(TreeNode *root) {
        if (!root) return;
        
        if (root->val == first) {
            start = root;
        }
        
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        
        dfs(root->left);
        dfs(root->right);
    }
    
    int count(TreeNode *root, TreeNode *prev) {
        if (!root || root == prev) return 0;
        
        int ans = 1; // Count this node itself
        
        // Traverse left, right, and parent (if they are not the previous node)
        if (root->left != prev) ans += count(root->left, root);
        if (root->right != prev) ans += count(root->right, root);
        if (parent[root] != prev) ans += count(parent[root], root);
        
        return ans;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        first = x;
        parent[root] = nullptr;
        
        // Perform DFS to build parent relationships and locate the node with value x
        dfs(root);
        
        // Calculate sizes of subtrees
        int leftSize = count(start->left, start);    // Left subtree of x
        int rightSize = count(start->right, start);  // Right subtree of x
        int parentSize = count(parent[start], start); // "Parent" subtree of x
        
        // Player 2 wins if they can control more than half the nodes
        int maxOpponent = max({leftSize, rightSize, parentSize});
        return maxOpponent > n / 2;
    }
};

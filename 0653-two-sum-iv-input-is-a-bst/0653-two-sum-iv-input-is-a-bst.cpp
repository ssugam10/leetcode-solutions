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





class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;
    
    BSTIterator(TreeNode* root, bool isReversed) {
        reverse = isReversed;
        pushAll(root,reverse);
    }
    
    int next() {
        TreeNode *curr = st.top();
        st.pop();
        if(reverse){
            pushAll(curr->left,true);
        }
        else pushAll(curr->right,false);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode *node, bool reverse){
        for(; node != NULL; ){
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)   return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i = l.next();
        int j = r.next();
        
        while(i < j){
            if(i + j == k)  return true;
            else if(i + j > k)  j = r.next();
            else i = l.next();
        }
        
        return false;
    }
};
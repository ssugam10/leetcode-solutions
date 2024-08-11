/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int findMaxDepth(Node *root, Node *parent){
        
        int depth = 0;
        for(auto adjNode : root->children){
            if(adjNode == parent)   continue;
            
            depth = max(depth, findMaxDepth(adjNode, root));
        }
        
        return depth + 1;
    }
    
    int maxDepth(Node* root) {
        if(!root)   return 0;
        return findMaxDepth(root,NULL);
    }
};
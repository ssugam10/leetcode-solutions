/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_set<int> visited;

    unordered_map<Node*,Node*> mp;

    Node *dfs(Node *node){
        Node *temp = new Node(node->val);
        mp[node] = temp;
        visited.insert(temp->val);  //tells us that if the node of new graph is already created or not
        for(auto ele : node->neighbors){
            if(!visited.count(ele->val)){
                dfs(ele);
            }
            temp->neighbors.push_back(mp[ele]);
        }
        return temp;
    }

    // Node* clone(Node *node){
    //     unordered_map<Node*,Node*> mp;
    //     queue<Node*> q;
    //     queue<Node*> track;
    //     Node *first = new Node(node->val);
    //     q.push(first);
    //     track.push(node);
    //     visited.insert(first->val);
    //     mp[node] = first;
    //     while(!q.empty()){
    //         Node *temp = q.front();
    //         node = track.front();
    //         track.pop();
    //         q.pop();
    //         for(auto ele : node->neighbors){
    //             if(!visited.count(ele->val)){
    //                 Node *adj = new Node(ele->val);
    //                 mp[ele] = adj;
    //                 q.push(adj);
    //                 track.push(ele);
    //                 visited.insert(adj->val);
    //             }
    //             temp->neighbors.push_back(mp[ele]);
    //         }
    //     }

    //     return first;
    // }

    Node* cloneGraph(Node* node) {
        if(!node)   return NULL;
        return dfs(node);
    }
};
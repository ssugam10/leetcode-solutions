class TrieNode{
public:
    TrieNode* children[26];
    int cost;
    
    TrieNode(){
        for(int i = 0; i<26; i++)   children[i] = NULL;
        cost = INT_MAX;
    }
};

class Trie{
public:
    TrieNode *root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word, int cost){
        TrieNode *node = root;
        for(int i = 0; i<word.size(); i++){
            int idx = word[i] - 'a';
            if(!node->children[idx]){
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        
        node->cost = min(node->cost,cost);
    }  
};


class Solution {
public:
    vector<int> dp;
    int m;

//     int f(string target, int i, Trie &trie){

//         if(i == m)  return 0;
        
//         if(dp[i] != -1) return dp[i];
        
//         int ans = INT_MAX;
//         TrieNode *node = trie.root;
//         for(int k = i; k<m; k++){
//             int idx = target[k] - 'a';
//             if(!node->children[idx])    break;
//             node = node->children[idx];
//             if(node->cost != INT_MAX){  //This node is the ending of a word in words array
//                 int call = f(target,k+1,trie);
//                 if(call != INT_MAX) ans = min(ans, call + node->cost);
//             }
//         }

//         return dp[i] = ans;
//     }
    

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        Trie trie;
        int n = words.size();
        for(int i = 0; i<n; i++){
            trie.insert(words[i],costs[i]);
        }
        
        m = target.size();
        dp.resize(m+1,-1);
        
        // int ans = f(target,0,trie);
        
        dp[m] = 0;
        for(int i = m-1; i>=0; i--){
            int ans = INT_MAX;
            TrieNode *node = trie.root;
            for(int k = i; k<m; k++){
                int idx = target[k] - 'a';
                if(!node->children[idx])    break;
                node = node->children[idx];
                if(node->cost != INT_MAX){  
                    int call = dp[k+1];
                    if(call != INT_MAX) ans = min(ans, call + node->cost);
                }
            }
            
            dp[i] = ans;
        }
        
        return (dp[0] == INT_MAX) ? -1 : dp[0];
        
    }
};
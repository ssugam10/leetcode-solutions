class Node{
    public: 
    char data;
    bool terminal;
    unordered_map<char,Node*> children; 
    Node(char data){
        this->data = data;
        this->terminal = false;
    }

    void makeTerminal(){
        this->terminal = true;
    }

    bool isTerminal(){
        return (this->terminal);
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node *curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];  //current character to be checked
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            }
            else{
                Node *child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }
        }

        curr->makeTerminal();
    }
    
    bool search(string word) {
        Node *curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch) == 0)   return false;
            else curr = curr->children[ch];
        }   
        return curr->isTerminal();
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for(int i = 0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(curr->children.count(ch) == 0)   return false;
            else curr = curr->children[ch];
        }   
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
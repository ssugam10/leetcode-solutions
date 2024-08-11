class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        
        while(!q.empty()){
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(curr == endWord) return steps;
            
            for(int i = 0; i<curr.length(); i++){
                
                for(char ch = 'a'; ch <= 'z'; ch++){
                    string newWord = curr;
                    newWord[i] = ch;
                    
                    if(st.find(newWord) != st.end()){
                        q.push({newWord,steps + 1});
                        st.erase(newWord);
                    }
                }
            }
        }
        
        return 0;
    }
};
class Solution {
public:
    vector<list<int>> graph;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int len = beginWord.length();
        graph.clear();
        graph.resize(n,list<int>());

        queue<int> q;
        vector<bool> visited(n,false);

        for(int i = 0; i<n; i++){
            int change = 0;
            for(int k = 0; k<len;k++){
                if(beginWord[k] != wordList[i][k])  change++;
            }
            if(change == 1){
                q.push(i);
                visited[i] = true;
            }

            for(int j = i+1; j<n ; j++){
                int diff = 0;
                for(int k = 0; k<len; k++){
                    if(wordList[i][k] != wordList[j][k])    diff++;
                }
                if(diff == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        q.push(-1);

        int dist = 2;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(curr == -1){
                if(q.size() == 0)   return 0;
                q.push(-1);
                dist++;
                continue;
            }

            if(wordList[curr] == endWord){
                return dist;
            }

            for(auto neigh : graph[curr]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }

        return 0;
    }
};
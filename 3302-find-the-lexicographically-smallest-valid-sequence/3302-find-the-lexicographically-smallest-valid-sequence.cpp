class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<int> last(m,-1); //we find the last occurence of word2[j] in word1 using this array 
        
        for(int i = n - 1, j = m - 1; i >= 0; i--){
            if(j >= 0 && word1[i] == word2[j]){
                last[j--] = i;
            }    
        }
        
        /* If we get a match then greedily take it, if we get a mismatch we try to take it right now, since taking early would
        make the ans lexicographically smaller, if now onwards, the sequence exists in the remaining subarray of word1 then 
        you can consider the current mismatch, otherwise you cant */
        
        vector<int> ans;
        
        int mismatch = 0;
        
        for(int i = 0, j = 0 ; i < n && j < m; i++){
            if(word1[i] == word2[j] || (mismatch == 0 && (j == m - 1 || last[j + 1] >= i + 1 ))){
                mismatch += (word1[i] != word2[j]);
                ans.push_back(i);
                j++;
            }
        }
        
        //for(int i= 0; i<ans.size(); i++)    cout<<ans[i]<<endl;
        
        return ans.size() == m ? ans : vector<int>();
    }
};
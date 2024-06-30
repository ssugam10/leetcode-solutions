class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        if(word1.length() != word2.length())    return false;
        
        unordered_map<char,int> mp1,mp2;  //we store the frequencies of each character in these maps for both words
        for(int i = 0; i<n; i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }   

        for(auto ele : mp1){
            if(mp2.find(ele.first) == mp2.end())    return false;   //if char in word1 is not present in word2 then obv false
        }   

        unordered_map<int,int> freq;
        for(auto ele : mp1){
            freq[ele.second]++; //We are storing the frequences of frequencies of characters, they should be same for both words
        }

        for(auto ele : mp2){
            if(freq[ele.second] == 0)   return false;   
            freq[ele.second]--;
        }

        return true;
    }
};
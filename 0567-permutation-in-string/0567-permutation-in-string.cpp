class Solution {
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        
        vector<int> f1(26, 0); // f1 is the frequency array for s1
        for(char c: s1) f1[c - 'a']++;
        
        vector<int> f2(26, 0); // f2 is the frequency array for the sliding window in s2
        int i = 0, j = 0;
        
        while(j < s2.size()) {
            f2[s2[j] - 'a']++;
            
            if(j - i + 1 == s1.size()) {
                if(areVectorsEqual(f1, f2)) return true;
            }
            
            if(j - i + 1 < s1.size()) j++;
            else {
                f2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};

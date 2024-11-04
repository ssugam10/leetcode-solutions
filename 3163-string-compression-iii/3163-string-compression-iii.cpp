class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string comp = "";
        
        int cnt = 1;
        char ch = word[0];
        
        for(int i = 1; i<n; i++){
            
            if(word[i] != ch || cnt == 9){
                comp += (char)('0' + cnt);
                comp += ch;
                
                ch = word[i];
                cnt = 1;
            }
            
            else if(word[i] == ch)   cnt++;
        }
        
        comp += (char)('0' + cnt);
        comp += ch; 
        
        return comp;
    }
};
class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string comp = "";
        int qty = 0;
        for(int i = 0; i<n; i++){
            if(i == 0)  qty = 1;
            else{
                if(word[i] == word[i-1] && qty < 9){
                    qty++;
                }
                else{
                    comp += (to_string(qty) + word[i-1]);
                    qty = 1;
                }
            }
        }
        
        comp += (to_string(qty) + word[n-1]);
        
        return comp;
        
    }
};
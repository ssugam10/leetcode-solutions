class Solution {
public:
    string makeDigit(int num, int digits){
        string s = to_string(num);
        int n = s.length();
        
        for(int i = 0; i<(digits - n); i++){
            s = '0' + s;
        }
        
        return s;
    }
    
    unordered_set<string> makeSwapChanges(int num, int digits){
        string s = makeDigit(num,digits);
        unordered_set<string> poss;
        
        poss.insert(s);
        
        for(int i = 0; i<digits; i++){
            for(int j = i + 1; j<digits; j++){
                swap(s[i],s[j]);
                poss.insert(s);
                
                for(int i1 = 0; i1<digits; i1++){
                    for(int j1 = i1 + 1; j1 < digits; j1++){
                        swap(s[i1],s[j1]);
                        
                        poss.insert(s);
                        
                        swap(s[i1],s[j1]);
                    }
                }
                
                swap(s[i],s[j]);
            }
        }
        
        return poss;
    }
    
    int countPairs(vector<int>& nums) {
        int digits = to_string(*max_element(nums.begin(),nums.end())).length();
        int n = nums.size();
        
        unordered_map<string,int> mp;
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            unordered_set<string> st = makeSwapChanges(nums[i],digits);
            for(auto &ele : st){
                ans += mp[ele];
            }
            
            mp[makeDigit(nums[i],digits)]++;
        }
        
        return ans;
    }
};
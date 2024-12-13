#define ll long long int

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        
        map<int,set<int>> mp;
        
        for(int i = 0; i<n; i++){
            mp[nums[i]].insert(i);
        }
        
        ll score = 0;
        
        set<int> prohibited;
        
        for(auto ele : mp){
            while(ele.second.size() > 0){
                int curr = *(ele.second.begin());
            
                if(prohibited.find(curr) != prohibited.end()){
                    ele.second.erase(ele.second.begin());
                    continue;
                }

                score += 1LL * ele.first;

                prohibited.insert(curr);
                prohibited.insert(curr + 1);
                prohibited.insert(curr - 1);

                ele.second.erase(ele.second.begin());
            }
            
        }
        
        return score;
    }
};
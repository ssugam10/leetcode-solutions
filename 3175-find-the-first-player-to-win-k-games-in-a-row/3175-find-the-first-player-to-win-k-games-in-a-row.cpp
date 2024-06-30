class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int mex = -1;
        int mexIdx = -1;
        
        // Find the maximum skill and its index
        for(int i = 0; i < n; i++){
            if(skills[i] > mex){
                mex = skills[i];
                mexIdx = i;
            }
        }
        
        // If k is greater than or equal to the number of players, return the index of the maximum skill
        if(k >= n)  return mexIdx;
        

        int streak = 0;
        for(int i = 0; i < n; i++){
            int val = skills[i];
            int j = i+1;
            if(j >= n){
                break;
            }
            
            while(j<n && skills[i] > skills[j]){
                streak++;
                j++;
                if(streak >= k) return i;
            }
            if(j == n)  break;
            streak = 1;
            if(k == 1)  return j;
            
            i = j-1;
        }
        
        return mexIdx;
    }
};

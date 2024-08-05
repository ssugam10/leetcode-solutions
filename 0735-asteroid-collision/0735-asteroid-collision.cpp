class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        int n = asteroids.size();
        
        for(int i = 0; i<n; i++){
            if(asteroids[i] > 0){
                st.push_back(asteroids[i]);
            }
            else{
                while(!st.empty() && st[st.size() - 1] > 0 && st[st.size() - 1] < abs(asteroids[i]))    st.pop_back();
                
                if(!st.empty() && st[st.size() - 1] == abs(asteroids[i]))    st.pop_back();
                
                else if(st.empty() || st[st.size() - 1] < 0)    st.push_back(asteroids[i]);
            }
        }
        
        return st;
    }
};
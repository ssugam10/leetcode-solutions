class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int m = obstacles.size();
        
        set<string> st;
        
        for(int i = 0; i<m; i++){
            st.insert(to_string(obstacles[i][0]) + " " + to_string(obstacles[i][1]));
        }
        
        int dist = 0;
        int dir = 0;
        int n = commands.size();
        
        int x = 0;
        int y = 0;
        
        for(int i = 0; i<n; i++){
            if(commands[i] == -1){
                dir++;
                dir %= 4;
            }
            else if(commands[i] == -2){
                dir--;
                dir = (dir + 4) % 4;
            }
            else{
                int forward = commands[i];
                
                for(int k = 1; k <= forward; k++){
                    int newX = x + dirs[dir].first;
                    int newY = y + dirs[dir].second;
                    
                    if(st.find(to_string(newX) + " " + to_string(newY)) != st.end())  break;
                    
                    x = newX;
                    y = newY;
                }
            }
            
            dist = max(dist, (int)(pow(x,2) + pow(y,2)));
        }
        
        return dist;
    }
};
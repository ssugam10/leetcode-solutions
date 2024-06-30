class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballToColor;  // map from ball to its current color
        unordered_map<int, unordered_set<int>> colorToBalls; // map from color to the set of balls
        
        vector<int> result;
        
        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];
            
            if (ballToColor.find(ball) != ballToColor.end()) {   // if ball is previously colored
                int prevColor = ballToColor[ball];
                
                // Remove the ball from the previous color set
                colorToBalls[prevColor].erase(ball);
                
                // If no balls are left with the previous color, remove the color from the map
                if (colorToBalls[prevColor].empty()) {
                    colorToBalls.erase(prevColor);
                }
            } 
            
            // Update the ball's color
            ballToColor[ball] = color;
            
            // Add the ball to the new color set
            colorToBalls[color].insert(ball);
            
            // Append the current number of unique colors to the result
            result.push_back(colorToBalls.size());
        }
        
        return result;
    }
};

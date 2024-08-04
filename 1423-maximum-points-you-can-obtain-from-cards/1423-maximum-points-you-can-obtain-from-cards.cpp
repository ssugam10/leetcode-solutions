class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        // Calculate the initial sum of the first k cards
        int currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += cardPoints[i];
        }
        
        int maxSum = currentSum;
        
        // Sliding window: move the window from the start to the end
        for (int i = 0; i < k; i++) {
            currentSum -= cardPoints[k - 1 - i];
            currentSum += cardPoints[n - 1 - i];
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};

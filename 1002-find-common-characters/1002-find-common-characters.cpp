class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> cummulative;
        // Initialize the cummulative map with the first word
        for (char c : words[0]) {
            cummulative[c]++;
        }

        // Iterate over the rest of the words
        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> mp;
            // Count the characters in the current word
            for (char c : words[i]) {
                mp[c]++;
            }

            // Update the cummulative map
            for (auto it = cummulative.begin(); it != cummulative.end();) {
                if (mp.find(it->first) == mp.end()) {
                    // Character not found in the current word, remove it
                    it = cummulative.erase(it);
                } else {
                    // Character found, update its count to the minimum
                    it->second = min(it->second, mp[it->first]);
                    ++it;
                }
            }
        }

        vector<string> ans;
        // Convert the cumulative map to the result vector
        for (auto ele : cummulative) {
            for (int i = 0; i < ele.second; i++) {
                ans.push_back(string(1, ele.first));
            }
        }

        return ans;
    }
};

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<double> av;
        for(int i = 0; i<nums.size()/2; i++){
            av.push_back((nums[i] + nums[nums.size()-i-1])/2.0);
        }
        
        double m = 1000;
        for(int i = 0; i<av.size(); i++){
            if(av[i] < m){
                m = av[i];
            }
        }
        
        return m;
    }
};
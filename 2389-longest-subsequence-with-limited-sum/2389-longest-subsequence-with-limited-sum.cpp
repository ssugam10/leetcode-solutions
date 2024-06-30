class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(),nums.end());
        for(int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }
        //nums now holds its own prefix sum

        vector<int> answer;
        for(int i = 0; i<m; i++){
            int target = queries[i];
            int mindx = -1; //v.imp to take -1 since lenth may also be zero if nums[i]>query[k], k->fixed
            int lo = 0;
            int hi = n-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(nums[mid]<=target){
                    mindx = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            answer.push_back(mindx+1);
            //pushing back mindx+1 since indexing starts from 0 !!!
        }
        return answer;
    }
};
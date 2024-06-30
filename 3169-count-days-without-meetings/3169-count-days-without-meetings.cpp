bool compareFirstElement(const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(), compareFirstElement);
        
        
        int n = meetings.size();
        
        // for(int i = 0; i<n; i++){
        //     cout<<meetings[i][0]<<" "<<meetings[i][1]<<endl;
        // }
        
        int count = 0;
        int endTime = 0;
        
        if(meetings[0][0] > 1)  count+= (meetings[0][0] - 1);
        
        for(int i =0; i<n ; i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            
            
            
            if(start > endTime && i!=0){
                count += (start - endTime - 1);
            }
            
            endTime = max(endTime, end);
        }
        
        
        
        if(endTime < days) count+= (days - endTime);
        
        return count;
    }
};
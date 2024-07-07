class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int len = colors.size();
        
        for(int i = 0; i<k-1; i++){
            colors.push_back(colors[i]);
        }
        
        int n = colors.size();
        
        vector<int> pre(n,0);
        
        for(int i = 0; i<n-1; i++){
            if(colors[i] == colors[i+1])    pre[i] = 1;
        }
         
        
        for(int i = 1; i<n; i++)    pre[i] += pre[i-1];
        
        //for(int i = 0; i<n; i++)    cout<<pre[i]<<" ";
        
        int ct = 0;
        
        for(int i = 0; i<len; i++){
            int j = i + k - 2;
            
            int diff;
            if(i == 0)  diff = pre[j];
            else diff = pre[j] - pre[i-1];
                
            if(diff == 0)   ct++;
        }
        
        return ct;
    }
};




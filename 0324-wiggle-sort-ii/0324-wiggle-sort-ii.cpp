class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return;
        
        sort(nums.begin(),nums.end());
        
        int mark = ceil((double)n / 2);
        
        vector<int> v;
        
        for(int i = 0; i<mark; i++){
            v.push_back(nums[i]);
            if(n % 2 == 0 || ((n & 1) && (i < mark - 1)))    v.push_back(nums[i + mark]);
        }
        
        // for(int i = 0; i<v.size(); i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        
        vector<int> final;
        
        for(int i = 0; i<n-1; i++){
            if(v[i] == v[i + 1]){
                vector<int> fhalf(v.begin(),v.begin() + i + 1);
                vector<int> shalf(v.begin() + i + 1, v.end());

//                 for(int i = 0; i<fhalf.size(); i++){
//                     cout<<fhalf[i]<<" ";
//                 }
//                 cout<<endl;

//                 for(int i = 0; i<shalf.size(); i++){
//                     cout<<shalf[i]<<" ";
//                 }
//                 cout<<endl;

                for(int i = 0; i<fhalf.size(); i++){
                    shalf.push_back(fhalf[i]);
                }

                final = shalf;
                
                nums = final;
                return;
            }
        }
        
        nums = v;
    }
};
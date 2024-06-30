class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int n = arr.size();
       vector<int> dist(n);

       for(int i = 0; i<n; i++){
            dist[i] = abs(x - arr[i]);
            //cout<<dist[i]<<endl;
        }
        //cout<<endl;

        auto comp = [](pair<int,int> a, pair<int,int> b){
            if(a.first == b.first)  return a.second < b.second;
            return a.first < b.first;
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(comp)> pq(comp);

        vector<int> ans;

        for(int i = 0; i<n; i++){
            pq.push({dist[i],arr[i]});
            if(pq.size() > k){
                //cout<<"The element that got popped is : "<<pq.top().first<<" "<<pq.top().second<<endl;
                pq.pop();
            }   
        } 

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            //cout<<pq.top().first <<" "<<pq.top().second<<endl;
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> parent; //parent[i] denotes the parent of the ith index of stones array (vertices array)
    vector<int> size;

    vector<pair<int,int>> edgeList;

    int find(int x){
        if(x == parent[x])  return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] >= size[b])
        {
            size[a] += size[b];
            parent[b] = a;
        }
        else
        {
            size[b] += size[a];
            parent[a] = b;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i<n ;i++){
            parent[i] = i;
        }

        for(int i = 0; i<n; i++){
            for(int j = i + 1 ; j<n ; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    edgeList.push_back({i,j});
                }
            }
        }

        for(int i = 0 ; i<edgeList.size(); i++){
            Union(edgeList[i].first, edgeList[i].second);
        }

        unordered_set<int> cc;
        for(int i = 0; i<n; i++){
            cc.insert(find(i));
            // cout<<parent[i]<<endl;
        }

        int num = cc.size();    

        return n - num;
    }
};
class Solution {
public:
    vector<int> parent; //parent[i] denotes the parent of the ith index of stones array (vertices array)
    vector<int> size;

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

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i<n ;i++){
            parent[i] = i;
        }

        int m = edges.size();
        for(int i = 0; i<m; i++){
            Union(edges[i][0],edges[i][1]);
        }

        unordered_set<int> cc;
        vector<int> sizes;

        for(int i = 0; i<n ;i++){
            int ancestor = find(i);
            if(!cc.count(ancestor)){
                cc.insert(ancestor);
                sizes.push_back(size[ancestor]);
            }
        }

        int k = sizes.size();
        long long ans = 0;
        long long rem = n;
        for(int i = 0; i<k; i++){
            rem -= sizes[i];
            ans += (rem*sizes[i]);
        }

        return ans;
    }
};
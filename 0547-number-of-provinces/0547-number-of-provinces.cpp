class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x){
        if(x == parent[x])  return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b)  return;

        if(rank[a] >= rank[b]){
            parent[b] = a;
            rank[a]++;
        }
        else{
            parent[a] = b;
            rank[b]++;
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        rank.resize(n,0);
        parent.resize(n);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i != j && isConnected[i][j]){
                    Union(i,j);
                }
            }
        }

        unordered_set<int> provinces;
        for(int i = 0; i<n; i++){
            provinces.insert(find(i));
        }

        return provinces.size();
    }
};
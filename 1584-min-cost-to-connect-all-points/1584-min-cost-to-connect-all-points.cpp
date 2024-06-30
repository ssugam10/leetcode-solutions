#define ll long long int 
class Solution {
public:
    struct Edge{
        int src;
        int dest;
        int wt;
    };

    int find(vector<int> &parent, int x)
    {
        // This method return which group/cluster x belongs to
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);
    }

    void Union(vector<int> &parent, vector<int> &rank, int a, int b)
    {
        a = find(parent, a);
        b = find(parent, b);

        if (rank[a] > rank[b])
        {
            parent[b] = a;
        }
        else if (rank[b] > rank[a])
        {
            parent[a] = b;
        }
        else
        {
            parent[b] = a;
            rank[a]++; // rank represents the height of the tree if path compression was not applied to the tree
        }
    }

    ll kruskal(vector<Edge> edgeList, int n){
        sort(edgeList.begin(),edgeList.end(), [](Edge a,Edge b){
            return a.wt < b.wt;
        });

        vector<int> parent(n);
        vector<int> rank(n,1);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        int i = 0;  //iterates over the edgeList
        int edgeCount = 0; //number of edges taken

        ll ans = 0;

        while(i<edgeList.size() && edgeCount < n-1){
            Edge curr = edgeList[i];
            int srcParent = find(parent,curr.src);
            int destParent = find(parent,curr.dest);
            if(srcParent != destParent){
                Union(parent,rank,srcParent,destParent);
                edgeCount++;
                ans += curr.wt;
            }
            i++;
        }

        return ans;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edgeList;
        for(int i = 0; i<n; i++){
            for(int j = i + 1; j<n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edgeList.push_back({src : i, dest: j, wt: dist});
            }
        }

        return kruskal(edgeList,n);
    }
};
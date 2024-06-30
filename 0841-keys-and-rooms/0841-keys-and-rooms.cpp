class Solution {
public:
    unordered_set<int> visited;

    void visit(vector<vector<int>>& rooms, int curr){
        visited.insert(curr);
        for(int i = 0 ; i<rooms[curr].size(); i++){
            if(visited.find(rooms[curr][i]) == visited.end())    visit(rooms,rooms[curr][i]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visit(rooms,0);

        if(visited.size() == n) return true;
        return false;
    }
};
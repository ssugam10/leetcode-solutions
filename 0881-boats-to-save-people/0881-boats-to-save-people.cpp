class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boats = 0;
        sort(people.begin(),people.end());
        int i = 0;
        int j = people.size()-1;
        while(j>i){
            if(people[i] + people[j] <= limit){
                boats++;
                i++;
                j--;
            }
            else{
                boats++;
                j--;
            }
        }
        if(i==j){
            boats++;
        }

        return boats;
    }
};
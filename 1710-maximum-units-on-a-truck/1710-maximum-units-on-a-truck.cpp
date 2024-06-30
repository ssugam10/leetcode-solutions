bool cmp(vector<int> &arr1, vector<int> &arr2){
    return arr1[1] > arr2[1];
}

class Solution {
public:
    

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);

        int units = 0;
        for(int i = 0; i<boxTypes.size(); i++){
            if(boxTypes[i][0] < truckSize){
                truckSize -= boxTypes[i][0];
                units += (boxTypes[i][0] * boxTypes[i][1]);
            }
            else{
                units += (truckSize * boxTypes[i][1]);
                truckSize = 0;
                break;
            }
        }
        return units;
    }
};
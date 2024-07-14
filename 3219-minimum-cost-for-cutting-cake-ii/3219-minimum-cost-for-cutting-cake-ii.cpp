#define ll long long int

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(verticalCut.begin(),verticalCut.end(),[](int a, int b){
            return a > b;
        });
        
        sort(horizontalCut.begin(),horizontalCut.end(),[](int a, int b){
            return a > b;
        });
        
        ll price = 0;
        int i = 0;
        int j = 0;
        
        ll horizontal_blocks = 1;
        ll vertical_blocks = 1;
        
        while(i < m-1 && j < n-1){
            if(horizontalCut[i] >= verticalCut[j]){
                price += (ll)horizontalCut[i] * vertical_blocks;
                horizontal_blocks++;
                i++;
            }
            else{
                price += (ll)verticalCut[j] * horizontal_blocks;
                vertical_blocks++;
                j++;
            }
        }
        
        while(i < m-1){
            price += (ll)horizontalCut[i] * vertical_blocks;
            horizontal_blocks++;
            i++;
        }
        
        while(j < n-1){
            price += (ll)verticalCut[j] * horizontal_blocks;
            vertical_blocks++;
            j++;
        }
        
        return price;
    }
};
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        if(n==1) return customers[0];
        if(minutes == n){
            int sum = 0;
            for(int i  = 0; i<n ; i++){
                sum += customers[i];
            }
            return sum;
        }
        int unsatisfied = 0;
        int maxUnsatisfied = 0;
        for(int i = 0; i<minutes; i++){
            if(grumpy[i]==1) unsatisfied += customers[i];
        }
        maxUnsatisfied = unsatisfied;
        int maxIdx = 0;
        int i = 1;
        int j = minutes;
        while(j<n){
            unsatisfied += (customers[j]*grumpy[j] - customers[i-1]*grumpy[i-1]);
            if(maxUnsatisfied < unsatisfied){
                maxUnsatisfied = unsatisfied;
                maxIdx = i;
            }
            i++;
            j++;
        }
        //filling 0s in the grumpy array window
        for(int i = maxIdx; i<(maxIdx+minutes); i++){
            grumpy[i] = 0;
        }

        //calculating sum of satisfaction
        int satisfied = 0;
        for(int i = 0; i<n; i++){
            if(grumpy[i]==0){
                satisfied += customers[i];
            }
        }
        return satisfied;
    }
};
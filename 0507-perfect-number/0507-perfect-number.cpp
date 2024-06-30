class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        int end = (int)sqrt(num);
        for(int i = 1; i<sqrt(num); i++){
            if(num%i==0){
                sum += (i + (num/i));
            }   
        }
        if(end*end==num) sum += end;

        return(sum>>1 == num);  //right shift since same number is added in first iteration of loop
    }
};
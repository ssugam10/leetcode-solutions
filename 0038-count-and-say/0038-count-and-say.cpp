class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string newString = "";
        string oldString = countAndSay(n-1);
        int length = oldString.length();
        int count = 1;
        for(int i=0; i<length; i++){
            if(oldString[i]==oldString[i+1]){
                count++;
                continue;
            }
            newString = newString + to_string(count) + oldString[i];
            count = 1;
        }
        return newString;
    }
};
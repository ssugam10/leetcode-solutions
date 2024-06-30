class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q;
        queue<int> r;
        queue<int> d;
        for(int i = 0; i<senate.length(); i++){
            q.push(i);
            if(senate[i]=='R')  r.push(i);
            else d.push(i);
        }
        while(q.size()>1){
            if(senate[q.front()] == 'X')    q.pop();
            else if(senate[q.front()] == 'R'){
                if(d.size()==0) return "Radiant";
                else{
                    senate[d.front()] = 'X';
                    d.pop();    
                    //Till here we have successfully taken away the righs of the next D
                    q.push(q.front());
                    q.pop();
                    r.push(r.front());
                    r.pop();
                }
            }
            else{
                if(r.size()==0) return "Dire";  //Checking for victory
                else{
                    senate[r.front()] = 'X';
                    r.pop();    
                    //Till here we have successfully taken away the righs of the next R
                    q.push(q.front());
                    q.pop();
                    d.push(d.front());
                    d.pop();
                }
            }
        }
        if(r.empty())   return "Dire";
        return "Radiant";
    }
};
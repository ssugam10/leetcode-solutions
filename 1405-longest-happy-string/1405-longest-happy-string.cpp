class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        
        string str = "";
        
        while(!pq.empty()){
            auto hi = pq.top();
            pq.pop();
            auto bot = pq.top();

            if(hi.first == 0)  break;

            int diff = min(hi.first - bot.first, 2);

            if(diff == 0)   diff = 1;

            for(int i = 0; i < diff; i++){
                str += hi.second;
            }

            if(bot.first == 0)  break;
            
            str += bot.second;
            pq.pop();
            pq.push({bot.first - 1, bot.second});

            pq.push({hi.first - diff, hi.second});
            
        }
        
        return str;
    }
};
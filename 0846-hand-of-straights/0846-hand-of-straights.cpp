#define ll long long int
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ll n = hand.size();
        if(n % groupSize != 0)  return false;

        set<ll> s;
        unordered_map<ll,ll> mp;
        for(int i = 0; i<n; i++){
            mp[hand[i]]++;
            s.insert(hand[i]);
        }

        for(int i = 0 ; i < n/groupSize ; i++){
            ll ele = *(s.begin());
            for(int j = 0; j<groupSize; j++){

                if(mp[ele] > 0) mp[ele]--;
                else return false;

                if(mp[ele] == 0){
                    mp.erase(ele);
                    s.erase(s.begin());
                }
                ele++;
            }

        }

        return true;
    }
};
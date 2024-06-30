class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int fidx = -1;
        int sidx = -1;
        ListNode *a = head;
        ListNode *b = head->next;
        ListNode *c = head->next->next;

        int mind = INT_MAX;
        int f = -1;
        int s = -1;
        if(c==NULL) return {-1,-1};
        while(c){
            if(b->val > a->val && b->val > c->val  || b->val < a->val && b->val < c->val){
                //For calculating the maximum distance
                if(fidx==-1) fidx = idx;
                else sidx = idx;

                //for calculating the minimum distance
                f = s;
                s = idx;
                if(f!=-1){
                    int d = s - f;
                    mind = min(mind,d);
                }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if(sidx==-1)    return {-1,-1};
        int maxd = sidx - fidx;
        return {mind,maxd};
    }
};
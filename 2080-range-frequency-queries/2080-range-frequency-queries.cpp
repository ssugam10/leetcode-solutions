class RangeFreqQuery {
public:
    vector<unordered_map<int,int>> st;
    vector<int> nums;
    int n;

    void buildTree(vector<int>& nums, int i, int lo, int hi){
        if(lo == hi){
            st[i][nums[lo]]++;
            return;
        }

        int mid = lo + (hi - lo)/2;
        buildTree(nums,2*i+1,lo,mid);
        buildTree(nums,2*i+2,mid+1,hi);

        for(auto ele : st[2*i+1]){
            st[i][ele.first] += ele.second;
        }
        for(auto ele : st[2*i+2]){
            st[i][ele.first] += ele.second;
        }
    }

    RangeFreqQuery(vector<int>& arr) {
        nums = arr;
        n = nums.size();
        st.resize(4*n);
        buildTree(nums,0,0,n-1);
    }

    int findFreq(int i, int lo, int hi, int &l, int &r, int &value){
        if(r < lo || l > hi){   //outside lie case, we return int min
            return 0;
        }

        if(lo >= l && hi <= r){
            return st[i][value];
        }

        int mid = lo + (hi-lo)/2;
        int leftFreq = findFreq(2*i+1,lo,mid,l,r,value);
        int rightFreq = findFreq(2*i+2,mid+1,hi,l,r,value);
        return leftFreq + rightFreq;
    }
    
    int query(int left, int right, int value) {
        return findFreq(0,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
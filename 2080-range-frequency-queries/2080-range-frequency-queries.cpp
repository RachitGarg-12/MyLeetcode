class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> m;
    RangeFreqQuery(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        vector<int> &cur=m[value];
        int st=lower_bound(cur.begin(),cur.end(),left)-cur.begin();
        int en=upper_bound(cur.begin(),cur.end(),right)-cur.begin();
        return en-st;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
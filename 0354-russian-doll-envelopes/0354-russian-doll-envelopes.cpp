class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),cmp);
        //if same len sort by decreasing order of width
        //so now we only have to look for lis in widt,as for same len it is already decreasing so multiple         will not count
        vector<int> temp;
        temp.push_back(a[0][1]);
        for(int i=1;i<n;i++){
            if(a[i][1]>temp.back()){
                temp.push_back(a[i][1]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),a[i][1])-temp.begin();
                temp[ind]=a[i][1];
            }
        }
        return temp.size();
    }
};
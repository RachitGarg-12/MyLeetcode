class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int n=a.size();sort(a.begin(),a.end());
        if(n%2){return {};}
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        vector<int> ans;bool b=true;
        for(int i=0;i<n;i++){
            if(m[a[i]]>0){
                ans.push_back(a[i]);if(m[a[i]*2]==0){b=false;break;}
                m[a[i]]--;m[a[i]*2]--;
            }
        }
        if(b==false){return {};}
        return ans;
        
    }
};
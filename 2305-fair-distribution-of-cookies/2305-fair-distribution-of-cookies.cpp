class Solution {
public:
    int ans=INT_MAX;
    int distributeCookies(vector<int>& cookies, int k) 
    {
        int idx=0;
        vector<int>v(k,0);
        fun(idx,cookies,v,k);
        return ans;             
    }
    void fun(int idx,vector<int>&cookies,vector<int>&v,int &k)
    {
        if(idx >= cookies.size()) 
        {
            int temp=*max_element(v.begin(),v.end());
            if(temp<ans)
            {
                ans=temp;
            }
            return;
        }
        for(int i=0;i<k;i++)
        {
            v[i]=v[i]+cookies[idx];
            fun(idx+1,cookies,v,k);   
            v[i]=v[i]-cookies[idx];
        }
    }
};
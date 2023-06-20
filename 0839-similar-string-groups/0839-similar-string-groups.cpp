class Solution {
public:
    int find_par(int i,vector<int> &parent){
        if(parent[i]==i)
            return i;
        return parent[i]=find_par(parent[i],parent);//path compression
    }
    void union_(int i,int j,vector<int> &parent,vector<int> &rank)
    {
        i=find_par(i,parent);
        j=find_par(j,parent);
        if(rank[i]==rank[j])
        {
            parent[i]=j;
            rank[j]++;
        }
        else if(rank[i]>rank[j])
            parent[j]=i;
        else
            parent[i]=j;
    }

    bool is_match(string &a,string &b)
    {
        int cnt=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
                cnt++;
            if(cnt>2)
                return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n=strs.size();
        vector<int> parent(n),rank(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(is_match(strs[i],strs[j]))
                    union_(i,j,parent,rank);
    
        //to find number of groups just find number of parents (parent[i]==i)
        int ans=0;
        for(int i=0;i<n;i++)
            if(parent[i]==i)
                ans++;
        return ans;
    }
};
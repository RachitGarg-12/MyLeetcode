class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        vector<char>ch{'A','C','G','T'};
        int ans=0;
        set<string>st;
        st.insert(start);
        q.push(start);
        while(!q.empty())
        {
            int t=q.size();
            while(t--)
            {
                string s=q.front();q.pop();
                if(s==end)
                    return ans;
                for(int i=0;i<8;i++)
                {
                    string str=s;
                    for(char c:ch)
                    {
                        s[i]=c;
                        if(st.find(s)!=st.end())
                            continue;
                        for(auto x:bank)
                            if(s==x)
                                q.push(s),st.insert(s);
                    }
                    s=str;
                }
            }
            ans++;
        }
        return -1;
    }
};
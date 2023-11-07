class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size(),ans=1;
        vector<int> time(n);
        for(int i=0;i<n;i++){
            time[i]=(dist[i]%speed[i])?(dist[i]/speed[i])+1:(dist[i]/speed[i]);
        }
        sort(time.begin(),time.end());
        for(int i=1;i<n;i++){
            if(time[i]<=i){break;}
            ans++;
        }
        return ans;
    }
};
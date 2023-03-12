class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),comp); // sort by inc order of end time
        vector<int> done(2001,0);
        for(int i=0;i<n;i++){
            int st=tasks[i][0],en=tasks[i][1],dur=tasks[i][2];
            dur-=count(done.begin()+st,done.begin()+en+1,1);
            for(int j=en;dur>0;j--){
                dur-=!done[j];
                done[j]=1;
            }
        }
        return count(done.begin(),done.end(),1);
    }
};
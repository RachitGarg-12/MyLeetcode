class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        int cur_time=0,ans=0;
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> maxdur;
        for(int i=0;i<n;i++){
            if(cur_time+courses[i][0]<=courses[i][1]){
                maxdur.push(courses[i][0]);
                cur_time+=courses[i][0];
            }
            else if(!maxdur.empty() && maxdur.top()>courses[i][0]){
             if(cur_time-maxdur.top()+courses[i][0]<=courses[i][1]){
                cur_time-=maxdur.top();
                cur_time+=courses[i][0];
                maxdur.pop();
                maxdur.push(courses[i][0]);
             }
            }
        }
        return maxdur.size();
    }
};
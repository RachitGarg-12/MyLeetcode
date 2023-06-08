class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
       int i=0;
       int j=a[0].size()-1;
       int count=0;
       while(i<a.size()&&j>=0)
       {
           if(a[i][j]<0)
           {
               count+=(a.size()-i); // add Negative Count = Total Row - current Row
               j--; //decrease the Column Pointer ( j--)
           }
           else if(a[i][j]>=0)
           {
               i++; // increase the Row pointer ( i++ )
           }
       }
       return count;
    }
};
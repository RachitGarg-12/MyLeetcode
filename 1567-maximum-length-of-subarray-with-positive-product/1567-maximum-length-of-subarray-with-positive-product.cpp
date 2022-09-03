class Solution {
public:
    int getMaxLen(vector<int>& a) {
        vector<vector<int>> sa;int n=a.size();
        for(int i=0;i<n;i++){
             vector<int> temp;
            for(int j=i;j<n;j++){
                   if(a[j]==0){i=j;break;}
                   temp.push_back(a[j]);i=j;
            }
            if(temp.size()>0){sa.push_back(temp);}
        }
        int ans=0;
       for(auto i:sa){
           int f=-1,l;int fre=0;int len=i.size();
           for(int j=0;j<len;j++){
               if(i[j]<0){fre++;l=j;
                   if( f==-1){f=j;}}
           }
          if(f==-1 || fre%2==0){ans=max(ans,len);}
          else{ans=max(ans,max(len-(f+1),l));}
            // cout<<fre<<" "<<f<<" "<<l<<" "<<len<<" "<<ans<<endl;
       } 
       
    return ans;
    }
};
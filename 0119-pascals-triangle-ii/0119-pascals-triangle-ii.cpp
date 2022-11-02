class Solution {
public:
  vector<int> getRow(int rowIndex)
  {
  vector<vector<int>> result(rowIndex+1);
  int i;
  for(i=0;i<=rowIndex;i++)
  {
      result[i].resize(i+1);
      result[i][0]=result[i][i]=1;
      for(int j=1;j<i;j++)
      {
          result[i][j]=result[i-1][j-1]+result[i-1][j];
      }
  }
      return result[i-1]; 
    }
};
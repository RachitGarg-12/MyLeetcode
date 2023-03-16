class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cur=arr[0],win=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>cur){
                cur=arr[i];win=0;
            }
            win++;
            if(win==k){return cur;}
        }
        return cur;
    }
};
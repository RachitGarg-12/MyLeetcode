class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> div(k,0);
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                div[((arr[i] % k) + k) % k]++;
            }
            else{div[arr[i]%k]++;}
        }
        for(int i=0;i<k;i++){
            if(i==0){
                if(div[i]%2!=0){return false;}
            }
            else if(div[i]!=div[k-i]){return false;}
        }
        return true;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),mx=-1;
        int chunks=0;
        for(int i=0;i<n;i++){
            mx=max(mx,arr[i]);
            if(mx==i)chunks++;
        }
        return chunks;
    }
};
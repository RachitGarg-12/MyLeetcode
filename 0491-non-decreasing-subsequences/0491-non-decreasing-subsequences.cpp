class Solution {
public:
    map<vector<int>, int> res; 
    vector<vector<int>> ans;
    // function to generate all increasing subsequences
    void solve(vector<int> nums, int index, vector<int> output){
        
        // if the output vector has at least 2 elements, add it to the ans vector 
        if(output.size()>=2){
            // increment the count of this subsequence in the map
            res[output]++; 
            // if this is the first time this subsequence is encountered, add it to the ans vector
            if(res[output]==1)
                ans.push_back(output);
        }
        
        // loop through the remaining elements in the input vector
        for(int i=index;i<nums.size();i++){
            // if output vector is empty or current element is greater than or equal to the last element of the output vector, add it to the output vector
            if(output.size()==0 || nums[i]>=output.back())
                output.push_back(nums[i]);
            // recursively call the solve function for the remaining elements
            solve(nums, i+1, output);
            // backtrack by removing the last element from the output vector
            output.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // initialize output and ans vectors
        vector<int> output;
        // vector<vector<int>> ans;
        // call the solve function to generate all increasing subsequences
        solve(nums, 0, output);
        // return the ans vector
        return ans;
    }
};
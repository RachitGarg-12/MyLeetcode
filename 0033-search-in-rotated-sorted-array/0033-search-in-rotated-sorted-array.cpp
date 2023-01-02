class Solution {
public:
    int search(vector<int>& a, int target) {
                int n = a.size();
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(a[mid] == target) {
                return mid; // no need to store the answer, just return it
            }
            if((target >= a[0] && (a[mid] >= target || a[mid] < a[0])) ||
               (target < a[0] && (a[mid] < a[0] && a[mid] >= target))) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1; 
    }
};
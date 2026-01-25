class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k <= 1 || nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = k - 1;
        int mini = INT_MAX;
        while(j < nums.size()){
            int diff = nums[j] - nums[i];
            mini = min(mini, diff);
            i++; 
            j++;
        }
        return mini;
    }
};
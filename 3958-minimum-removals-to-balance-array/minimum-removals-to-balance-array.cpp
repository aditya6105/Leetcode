class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if(nums.empty()) return 0; 
        sort(nums.begin(), nums.end());
        int maxW = 0, left = 0;
        for(int i=0;i<nums.size();i++){
            while(left<=i && (long long)nums[left] * k < (long long)nums[i]) left++;
            int curr = i - left + 1;
            if(curr > maxW) maxW = curr;
        }
        return nums.size() - maxW;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int longest = 1;
        int lastSmallest = nums[0];
        for(int i=1;i<nums.size();i++){
            
            if(lastSmallest + 1 == nums[i]){
                cnt++;
                lastSmallest = nums[i];
            }
            
            else if(lastSmallest == nums[i]) continue;

            else if(lastSmallest != nums[i]){
                cnt = 1;
                lastSmallest = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};
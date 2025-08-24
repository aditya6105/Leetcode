class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroC = 0;
        int start = 0;
        int i = 0;
        int ans = 0;
        while(i < nums.size()){
            if(nums[i] == 0) zeroC++;
            while(zeroC > 1){
                if(nums[start] == 0) zeroC--;
                start++;
            }
            ans = max(ans, i - start);
            i++;
        }
        return ans;
    }
};
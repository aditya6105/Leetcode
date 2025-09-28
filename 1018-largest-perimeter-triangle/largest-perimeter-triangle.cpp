class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxP = 0;
        for(int k=nums.size()-1;k>=2;k--){
            int i = 0;
            int j = k - 1;
            while(i < j){
                if(nums[i] + nums[j] > nums[k]){
                    int pm = nums[i] + nums[j] + nums[k];
                    maxP = max(maxP, pm);
                }
                i++;
            }
        }
        return maxP;
    }
};
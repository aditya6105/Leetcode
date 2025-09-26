class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int c = 0;
        if(nums.size() <= 2) return c;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i] + nums[j] > nums[k]) c++;
                }
            }
        }
        return c;
    }
};
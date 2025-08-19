class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long c = 0, cons = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                cons++;
                c += cons;
            }
            else cons = 0;
        }
        return c;
    }
};
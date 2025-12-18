class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int c = 0;
        int sumL = 0;
        for(int i=0;i<nums.size() - 1;i++){
            sumL += nums[i];
            int sumR = 0;
            for(int j=i+1;j<nums.size();j++){
                sumR += nums[j];
            }
            int diff = sumL - sumR;
            if(diff % 2 == 0) c++;
        }
        return c;
    }
};
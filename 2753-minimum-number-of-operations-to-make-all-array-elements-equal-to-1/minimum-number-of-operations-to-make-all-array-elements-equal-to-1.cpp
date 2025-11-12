class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        int g = 0;
        for(auto it : nums){
            if(it == 1) one++;
            g = gcd(g, it);
        }
        
        if(one > 0) return n - one;
        if(g > 1) return -1;

        int minL = n;
        for(int i=0;i<n;i++){
            int g = 0;
            for(int j=i;j<n;j++){
                g = gcd(g, nums[j]);
                if(g == 1){
                    minL = min(minL, j - i + 1);
                    break;
                }
            }
        }
        return minL + n - 2;
    }
};
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                int j = i + 1;
                int c = 0;
                while(j < nums.size()){
                    if(nums[j] == 1){
                        if(c >= k) break;
                        else if(c < k) return false;
                    }
                    c++;
                    j++;
                }
            }
        }
        return true;
    }
};
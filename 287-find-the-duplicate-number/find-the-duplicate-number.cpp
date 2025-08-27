class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        while(low < high){
            int mid = low + (high - low) / 2;
            int c = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] <= mid) c++;
            }
            if(c > mid) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
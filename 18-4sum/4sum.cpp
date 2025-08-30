class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        if(nums.size() < 4) return v;
        set<vector<int>> s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int k = j+1;
                int l = nums.size() - 1;
                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum == target){
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        l--;
                        k++;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        for(auto it : s){
            v.push_back(it);
        }
        return v;
    }
};
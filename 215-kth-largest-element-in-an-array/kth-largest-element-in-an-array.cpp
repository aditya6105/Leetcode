class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> p;
        for(auto it : nums){
            p.push(it);
            if(p.size() > k) p.pop();
        }
        return p.top();
    }
};
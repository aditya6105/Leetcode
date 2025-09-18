#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        if (nums.empty() || k == 0) return v;

        // Sort as you had
        sort(nums.begin(), nums.end());

        // Frequency count properly while scanning sorted nums
        priority_queue<pair<int,int>> p;
        int cnt = 1;
        for (int i = 1; i <= nums.size(); i++) {
            if (i < nums.size() && nums[i] == nums[i-1]) {
                cnt++;
            } else {
                p.push({cnt, nums[i-1]}); // push {freq, value}
                cnt = 1;
            }
        }

        // Extract top k
        while (k-- && !p.empty()) {
            v.push_back(p.top().second);
            p.pop();
        }
        return v;
    }
};

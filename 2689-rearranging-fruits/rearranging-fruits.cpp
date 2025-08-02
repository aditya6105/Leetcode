class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> m;
        int mini = INT_MAX;
        for(auto it : basket1){
            m[it]++;
            mini = min(mini, it);
        }
        for(auto it : basket2){
            m[it]--;
            mini = min(mini, it);
        }
        vector<int> v;
        for(auto it : m){
            int cost = it.first;
            int c = it.second;
            if(c % 2 != 0) return -1;
            for(int i=1;i<=abs(c)/2;i++) v.push_back(cost);
        }
        sort(v.begin(), v.end());
        long long res = 0;
        for(int i=0;i<v.size()/2;i++){
            res += min(v[i], mini*2);
        }
        return res;
    }
};
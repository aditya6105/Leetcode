class Solution {
public:

    int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int combinations(vector<int> &v, int target, int ind){
        if(target == 0) return 1;
        if(target < 0 || ind == v.size()) return 0;
        if (dp[ind][target] != -1) return dp[ind][target];

        int inc = combinations(v, target - v[ind], ind + 1);
        int exc = combinations(v, target, ind + 1);

        return dp[ind][target] = (inc + exc) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<int> v;
        for(int i=1;i<=n;i++){
            long long p = 1;
            for(int j=0;j<x;j++) p *= i;
            if(p > n) break;
            v.push_back((int)p);
        }
        dp.assign(v.size(), vector<int>(n + 1, -1));
        int c = combinations(v, n, 0);
        return c;
    }
};
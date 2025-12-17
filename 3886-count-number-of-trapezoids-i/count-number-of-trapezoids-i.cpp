class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long comb2(long long x) {
        return x * (x - 1) / 2;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> cnt;
        for (auto &p : points) {
            cnt[p[1]]++;
        }

        long long ans = 0;
        long long sumPairs = 0;

        for (auto &p : cnt) {
            if (p.second >= 2) {
                long long cur = comb2(p.second) % MOD;
                ans = (ans + cur * sumPairs) % MOD;
                sumPairs = (sumPairs + cur) % MOD;
            }
        }
        return ans;
    }
};

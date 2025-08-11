class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MOD = 1000000007;
        vector<int> p;
        int temp = n;
        int power = 1;
        while(temp > 0){
            if(temp & 1) p.push_back(power);
            power <<= 1;
            temp >>= 1;
        }

        vector<int> ans;
        for(auto it : queries){
            long long prod = 1;
            for(int i=it[0];i<=it[1];i++){
                prod = (prod * p[i]) % MOD;
            }
            ans.push_back(int(prod));
        }
        return ans;
    }
};
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0;

        vector<long long> v(31, 0);
        v[0] = 1;
        for(int i=1;i<=30;i++) v[i] = 2 * v[i - 1] + 1;
        
        int res = 0;
        int sign = 1;
        for(int i=30;i>=0;i--){ // left to right
            int ith_bit = ((1 << i) & n);

            if(ith_bit == 0) continue;

            if(sign > 0) res += v[i];
            else res -= v[i];

            sign *= (-1);
        }
        return res;
    }
};
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        for(int k=1;k<=60;k++){
            long long x = num1 - 1ll * num2 * k;
            if(x < k) return -1;
            if(k >= __builtin_popcountll(x)) return k;
        }
        return -1;
    }
};
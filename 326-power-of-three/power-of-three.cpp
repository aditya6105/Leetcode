class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n > 1){
            if(n % 3 != 0) return 0;
            n = n / 3;  
        }
        if(n == 1) return 1;
        return 0;
    }
};
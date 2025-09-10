class Solution {
public:
    double myPow(double x, int n) {
        long temp = n;
        if(n < 0){
            x = 1/x;
            temp = -temp;
        }
        
        double a = 1.0;
        while(temp){
            if(temp % 2 == 1) a *= x;
            x *= x;
            temp /= 2;
        }
        return a;
    }
};
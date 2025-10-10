class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int low = 1;
        int high = x / 2;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(1ll * mid * mid == x) return mid;
            // cout<<mid<<endl;
            else if(1ll * mid * mid < x) low = mid + 1;
            else if(1ll * mid * mid > x) high = mid - 1;
        }
        return high;
    }
};
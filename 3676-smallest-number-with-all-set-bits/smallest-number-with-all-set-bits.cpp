class Solution {
public:
    int smallestNumber(int n) {
        int i = n;
        while(i <= 10000){
            int temp = i;
            bool flag = true;
            while(temp){
                if(temp % 2 == 0){
                    flag = false;
                    break;
                }
                temp /= 2;
            }
            if(flag == true) break;
            i++;
        }
        return i;
    }
};
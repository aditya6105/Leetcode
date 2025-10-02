class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int c = 0;
        for(int i=0;i<=numBottles;i++){
            if(c == numExchange){
                c = 0;
                numBottles++;
            }
            c++;
        }
        return numBottles;
    }
};
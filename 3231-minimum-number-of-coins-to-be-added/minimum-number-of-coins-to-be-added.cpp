class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int obtain = 0;
        int c = 0;
        sort(coins.begin(), coins.end());

        for(auto it : coins){
            while(it > obtain + 1){
                c++;
                int newCoin = obtain + 1;
                obtain += newCoin;
                if(obtain >= target) return c;
            }
            obtain += it;
            if(obtain >= target) return c;
        }

        while(obtain < target){
            c++;
            int newCoin = obtain + 1;
            obtain += newCoin;
        }
        return c;
    }
};
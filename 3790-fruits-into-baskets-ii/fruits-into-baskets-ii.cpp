class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int c = 0;
        for(int i=0;i<fruits.size();i++){
            int unplaced = 1;
            for(int j=0;j<baskets.size();j++){
                if(fruits[i] <= baskets[j]){
                    baskets[j] = 0;
                    unplaced = 0;
                    break;
                }
            }
            c += unplaced;
        }
        return c;
    }
};
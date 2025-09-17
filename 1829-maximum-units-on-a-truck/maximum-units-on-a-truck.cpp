class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto a, auto b){
            return a[1] > b[1];
        });
        int maxProfit = 0;
        for(auto it : boxTypes){
            int capacity = it[0];
            int unitCost = it[1];
            if(capacity <= truckSize){
                maxProfit += (unitCost * capacity);
                truckSize -= capacity;
            }
            else{
                maxProfit += (unitCost * truckSize);
                break;
            }
        }
        return maxProfit;
    }
};
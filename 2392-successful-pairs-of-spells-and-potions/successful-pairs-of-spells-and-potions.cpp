class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v;
        sort(potions.begin(), potions.end());
        for(int i=0;i<spells.size();i++){
            int low = 0;
            int high = potions.size() - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                long long strength = 1ll * spells[i] * potions[mid];
                if(strength >= success) high = mid - 1;
                else low = mid + 1;
            }
            if(potions.size() <= low) v.push_back(0);
            else v.push_back(potions.size() - low);
        }
        return v;
    }
};
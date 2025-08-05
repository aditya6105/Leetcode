class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int c = 0;
        unordered_map<int, int> m;
        int left = 0, right = 0;
        while(right < fruits.size()){
            m[fruits[right]]++;
            while(m.size() > 2){
                m[fruits[left]]--;
                if(m[fruits[left]] == 0) m.erase(fruits[left]);
                left++;
            }
            c = max(c, right - left + 1);
            right++;
        }
        return c;
    }
};
class Solution {
public:
    string sortVowels(string s) {
        unordered_map<int, int> m = {
            {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}, {'a', 5}, {'e', 6}, {'i', 7}, {'o', 8}, {'u', 9}
        };

        vector<char> v;
        for(auto it : s){
            if(m.find(it) != m.end()) v.push_back(it);
        }
        sort(v.begin(), v.end());

        int it = 0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i]) != m.end()){
                s[i] = v[it];
                it++;
            }
        }
        return s;
    }
};
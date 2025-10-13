class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // vector<string> dupli = words;
        vector<string> dupli;
        for(auto it : words){
            sort(it.begin(), it.end());
            dupli.push_back(it);
        }
        vector<int> v;
        for(int i=0;i<dupli.size();i++){
            if(i == 0){
                v.push_back(i);
                continue;
            }
            if(dupli[i-1] != dupli[i]) v.push_back(i);
        }
        dupli.clear();
        for(int i=0;i<v.size();i++) dupli.push_back(words[v[i]]);
        return dupli;
    }
};
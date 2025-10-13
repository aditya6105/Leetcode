class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> v;
        int ind = 0;
        v.push_back(words[ind]);
        for(int i=1;i<words.size();i++){
            if(v[ind].size() == words[i].size()){
                string s1 = v[ind];
                string s2 = words[i];
                sort(s1.begin(), s1.end());
                sort(s2.begin(), s2.end());
                if(s1 != s2){
                    v.push_back(words[i]);
                    ind++;
                }
            }
            else{
                v.push_back(words[i]);
                ind++;
            }
        }
        return v;

    }
};
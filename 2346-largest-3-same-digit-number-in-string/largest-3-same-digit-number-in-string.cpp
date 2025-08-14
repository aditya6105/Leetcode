class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        vector<string> v;
        for(int i=0;i<num.size();i++){
            int c = 0;
            int j = i;
            while(j < num.size() && num[i] == num[j]){
                c++;
                j++;
                if(c == 3){
                    v.push_back(num.substr(i, j-i));
                    break;
                }
            }
        }
        sort(v.begin(), v.end());
        if(!v.size()) return "";
        return v[v.size()-1];
    }
};
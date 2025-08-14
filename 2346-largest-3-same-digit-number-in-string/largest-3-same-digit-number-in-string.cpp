class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "";
        vector<string> v;
        for(int i=0;i<num.size();i++){
            int c = 0;
            for(int j=i;j<num.size();j++){
                if(num[i] == num[j]) c++;
                else break;
                if(c == 3){
                    v.push_back(num.substr(i, j-i+1));
                    break;
                }
            }
        }
        sort(v.begin(), v.end());
        if(!v.size()) return "";
        return v[v.size()-1];
    }
};
class Solution {
public:
    bool hasSameDigits(string s) {
        if(s.size() < 2) return false;
        while(s.size() > 2){
            string temp;
            for(int i=1;i<s.size();i++){
                int a = (s[i-1] + s[i]) % 10;
                temp += a;
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};
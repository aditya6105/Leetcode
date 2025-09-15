class Solution {
public:
    int canBeTypedWords(string t, string bl) {
        unordered_map<char, int> m;
        for(int i=0;i<bl.size();i++) m[bl[i]]++;
        int c = 0;
        int i = 0;
        while(i < t.size()){
            if(i < t.size() && t[i] == ' ') i++;
            int j = i;
            while(j < t.size() && t[j] != ' ') j++;
            while(i < j){
                if(m.count(t[i])) break;
                i++;
            }
            if(i == j) c++;
            else{
                i = j;
            }
        }
        return c;
    }
};
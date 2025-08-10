class Solution {
public:

    void perm(vector<int>& v, string& s, int left, int right){
        if(left == right){
            if(s[0] != '0') v.push_back(stoi(s));
            return;
        }

        for(int i=left;i<=right;i++){
            swap(s[left], s[i]);
            perm(v, s, left + 1, right);
            swap(s[left], s[i]);
        }
    }

    bool reorderedPowerOf2(int n) {
        vector<int> v;
        string s = to_string(n);
        perm(v, s, 0, s.size() - 1);

        for(int i=0;i<v.size();i++){
            if(v[i] > 0 && !(v[i] & (v[i]-1))) return true;
        }
        return false;
    }
};
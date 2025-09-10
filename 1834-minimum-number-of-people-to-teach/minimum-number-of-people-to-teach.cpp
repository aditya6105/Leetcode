class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& fs) {
        unordered_map<int, vector<int>> m;
        int k = 1;
        for(int i=0;i<lang.size();i++){
            m[k] = lang[i];
            k++;
        } 

        unordered_set<int> s;
        for(int i=0;i<fs.size();i++){
            int a = fs[i][0];
            int b = fs[i][1];
            
            if(m.find(a) != m.end() && m.find(b) != m.end()){
                vector<int> &v1 = m[a];
                vector<int> &v2 = m[b];

                unordered_set<int> set(v1.begin(), v1.end());
                bool flag = false;
                for(auto it : v2){
                    if(set.find(it) != set.end()){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    s.insert(a);
                    s.insert(b);
                }
            }
        }
        if(s.size() == 0) return 0;

        int ans = INT_MAX;
        for(int i=1;i<=n;i++){
            int c = 0;
            for(auto it : s){
                vector<int> &v = m[it];
                if(find(v.begin(), v.end(), i) == v.end()){
                    c++;
                }
            }
            ans = min(ans, c);
        }
        return ans;
    }
};
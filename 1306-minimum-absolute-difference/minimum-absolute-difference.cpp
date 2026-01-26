class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> v;
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for(int i=1;i<arr.size();i++) mini = min(arr[i] - arr[i - 1], mini);
        for(int i=1;i<arr.size();i++){
            int diff = arr[i] - arr[i - 1];
            if(diff == mini) v.push_back({arr[i - 1], arr[i]});
        }
        return v;
    }
};
class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0;
        int j = h.size() - 1;
        int area = 0;
        while(i < j){
            int height = min(h[i], h[j]);
            int dist = j - i;
            area = max(area, (height * dist));
            if(h[i] < h[j]) i++;
            else j--;
        }
        return area;
    }
};
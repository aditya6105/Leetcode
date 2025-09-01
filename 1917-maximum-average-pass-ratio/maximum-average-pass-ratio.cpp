double gain(int pass, int total) {
    return (1.0 * (pass + 1) / (total + 1)) - (1.0 * pass / total);
}

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> p;

        for (int i = 0; i < classes.size(); i++) {
            p.push({gain(classes[i][0], classes[i][1]), i});
        }

        while (extraStudents--) {
            int ind = p.top().second;
            p.pop();

            classes[ind][0] += 1;
            classes[ind][1] += 1;

            p.push({gain(classes[ind][0], classes[ind][1]), ind});
        }

        double sum = 0.0;
        for (auto &c : classes) {
            sum += 1.0 * c[0] / c[1];
        }
        return sum / classes.size();
    }
};

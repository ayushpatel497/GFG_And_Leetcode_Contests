class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        const int n = points.size();
        int r = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1, m = INT_MIN; j < n; ++j) {
                if (points[i][1] >= points[j][1] && m < points[j][1])
                    ++r;
                if (points[j][1] <= points[i][1])
                    m = max(m, points[j][1]);
            }
        }
        return r;
    }
};
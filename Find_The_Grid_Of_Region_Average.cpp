class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        const int m = image.size(), n = image[0].size();
        vector<vector<int>> sum(m, vector<int>(n)), num(m, vector<int>(n));
        for (int i = 1; i + 1 < m; ++i) {
            for (int j = 1; j + 1 < n; ++j) {
                bool ok = true;
                int s = 0;
                for (int x = i - 1; ok && x <= i + 1; ++x) {
                    for (int y = j - 1; ok && y <= j + 1; ++y) {
                        for (int xx = x - 1; ok && xx <= x + 1; ++xx) {
                            for (int yy = y - 1; ok && yy <= y + 1; ++yy) {
                                if (xx >= i - 1 && xx <= i + 1 && yy >= j - 1 && yy <= j + 1 && abs(xx - x) + abs(yy - y) == 1 && abs(image[x][y] - image[xx][yy]) > threshold) {
                                    ok = false;
                                } 
                            }
                        }
                        if (ok) {
                            s += image[x][y];
                        }
                    }
                }
                if (!ok) continue;
                s /= 9;
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        sum[x][y] += s;
                        ++num[x][y];
                    }
                }
            }
        }
        vector<vector<int>> r = image;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (num[i][j]) {
                    r[i][j] = sum[i][j] / num[i][j];
                }
            }
        }
        return r;
    }
};
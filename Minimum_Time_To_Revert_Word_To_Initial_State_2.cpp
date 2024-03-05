class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int> v(n);
        v[0] = n;
        for (int i = 1, left = 0, right = 0; i < n; i++) {
            if (i <= right)
                v[i] = min(v[i - left], right - i + 1);
            for (int &j = v[i]; i + j < n && word[j] == word[i + j]; j++);
            if (i % k == 0 && v[i] == n - i)
                return i / k;
            if (v[i] > right - i + 1)
                left = i, right = i + v[i] - 1;
        }
        return (n + k - 1) / k;
    }
};
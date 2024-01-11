class Solution {
public:
    int dp[20001];
    int dfs(int x, int y) {
        if(y >= x)
            return y - x;
        if(dp[x] != -1)
            return dp[x];
        int ret = x - y;
        ret = min(ret, dfs(x / 11, y) + x % 11 + 1);
        ret = min(ret, dfs(x / 11 + 1, y) + 11 - (x % 11) + 1);
        ret = min(ret, dfs(x / 5, y) + x % 5 + 1);
        ret = min(ret, dfs(x / 5 + 1, y) + 5 - (x % 5) + 1);
        return dp[x] = ret;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        memset(dp, -1, sizeof(dp));
        return dfs(x, y);
    }
};
class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0, n = word.size(), multiplier = 1;
        int quotient = n / 8;
        int remainder = n % 8;
        while (quotient--) {
            ans += 8 * multiplier;
            multiplier++;
        }
        ans += remainder * multiplier;
        return ans;
    }
};
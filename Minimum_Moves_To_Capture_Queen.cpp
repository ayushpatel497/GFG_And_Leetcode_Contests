class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (b == f)
            return d == f && a < c == c < e ? 2 : 1;
        if (a == e)
            return c == e && b < d == d < f ? 2 : 1;
        if (c - d == e - f)
            return a - b == e - f && c < a == a < e ? 2 : 1;
        if (c + d == e + f)
            return a + b == e + f && c < a == a < e ? 2 : 1;
        return 2;
    }
};
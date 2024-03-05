class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int ct = 1;
        for(int i=k; i<n; i+=k){
            if(word.substr(i, n-i) == word.substr(0, n-i)) return ct;
            else ct++;
        }
        return ct;
    }
};
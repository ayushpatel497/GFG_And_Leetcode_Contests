class Solution {
public:
    string lastNonEmptyString(string s) {
        int n=s.length();
        vector<int>v(26,0);
        for(auto c:s)
            v[c-'a']++;
        int maxx=INT_MIN;
        for(auto i:v) 
            maxx=max(maxx,i);
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(v[s[i]-'a']==maxx){
                ans=s[i]+ans;
                v[s[i]-'a']--;
            }
        }
        return ans;
    }
};
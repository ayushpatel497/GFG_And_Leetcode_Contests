class Solution {
private:
    bool check(char a,char b){
        if(a==b) return true;
        else if((a-'a') == (b-'A') || (a-'A') == (b-'a')) return true;
        return false;
    }
public:
    int countKeyChanges(string s) {
        int ct=0;
        for(int i=1;i<s.length();i++){
            if(!check(s[i],s[i-1])) ct++;
        }
        return ct;
    }
};
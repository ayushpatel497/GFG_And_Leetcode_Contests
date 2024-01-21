class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(begin(nums1),end(nums1));
        set<int>s2(begin(nums2),end(nums2));
        int n=nums1.size(),m=nums2.size();
        int x=s1.size(),y=s2.size();
        int ans=min(n/2,x);
        int rem=x-ans;
        int c=0;
        for(auto i:s2) {
            if(s1.find(i)==s1.end()) {
                c++;
            } else if(rem>0) {
                c++;
                rem--;
            }
            if(c>=m/2)
                break;
        }
        return ans+c;
    }
};
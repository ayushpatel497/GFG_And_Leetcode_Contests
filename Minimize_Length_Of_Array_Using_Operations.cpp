class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int c=1;
        int g=INT_MAX;
        for(int i=1;i<n;i++) {
            g=min(g,__gcd(nums[i],nums[i-1]));
            if(g<nums[0])
                return 1;
            if(nums[i]==nums[0])
                c++;
        }
        int k=ceil(c/(2*1.0));
        return k;
    }
};
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0,maxi=nums[nums.size()-1]+1,n=nums.size();
        vector<int> dp(maxi+1,0);
        for(int i=0;i<n;i++){
            dp[nums[i]+1]=dp[nums[i]]+1;
            dp[nums[i]]=dp[nums[i]-1]+1;
            ans=max(ans,max( dp[nums[i]],dp[nums[i]+1] ));
        }
        return ans;
    }
};
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        if(nums.size() == 2)
            return 1;

        dp[2][nums.size() - 1] = nums[0] + nums[1];
        dp[1][nums.size() - 2] = nums[0] + nums[nums.size() - 1];
        dp[0][nums.size() - 3] = nums[nums.size() - 2] + nums[nums.size() - 1];

        for(int len = nums.size() - 4; len >= 0; len -= 2){
            bool found = false;
            for(int i = 0; i <= nums.size() - len; i++){
                int j = i + len - 1;

                if(j + 2 < nums.size() && nums[j + 1] + nums[j + 2] == dp[i][j + 2]){
                    if(len)
                        dp[i][j] = dp[i][j + 2];
                    found = true;
                }

                else if(i - 2 >= 0 && nums[i - 1] + nums[i - 2] == dp[i - 2][j]){
                    if(len)
                        dp[i][j] = dp[i - 2][j];
                    found = true;
                }

                else if(i - 1 >= 0 && j + 1 < nums.size() && nums[i - 1] + nums[j + 1] == dp[i - 1][j + 1]){
                    if(len)
                        dp[i][j] = dp[i - 1][j + 1];
                    found = true;
                }
            }

            if(!found)
                return (nums.size() - len - 2) / 2;
        }

        return nums.size() / 2;
    }
};
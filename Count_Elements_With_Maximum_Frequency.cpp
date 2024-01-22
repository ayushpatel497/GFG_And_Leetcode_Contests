class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>um;
        for(int i:nums){
            um[i]++;
        }
        int maxx;
        int ans=0;
        for(auto i:um){
            if(i.second>maxx) maxx=i.second;
        }
        for(auto i:um)
        {
            if(i.second==maxx) ans+=i.second;
        }  
        return ans;
    }   
};
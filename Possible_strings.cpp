//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int PossibleStrings(int N, int K) {
        // code here
        if(K==1) return 0;
        long long ans = 1;
        vector<long long> dp(N+1,1);
        int MOD = 1e9+7;
        for(int i = 1; i<=N; i++){
            if(i<K){
                dp[i] = dp[i-1]*26;
            }else if(i==K){
                dp[i] = dp[i-1]*26;
                dp[i] -= 26;
            }else{
                dp[i] = dp[i-1]*26 - dp[i-K]*25;
            }
            dp[i]%=MOD;
            dp[i]+=MOD;
            dp[i]%=MOD;
        }
        return dp[N];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.PossibleStrings(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
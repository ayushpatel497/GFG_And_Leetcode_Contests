//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int mod=1e9+7;
class Solution {
  public:
    int findFun2(int n,vector<int>&memo){
        if(n==0)
            return 2;
        else if(n==1)
            return 5;
        else if(n==2)
            return 9;
        else if(n==3)
            return 7;
        if(memo[n]!=-1)
            return memo[n];
        int v1=findFun2(n-1,memo);
        int v2=findFun2(n-2,memo);
        int v3=findFun2(n-3,memo);
        int v4=findFun2(n-4,memo);
        if(n%2==0)
            return memo[n] = ((((long long)v2*(n-2))%mod)+(((long long)v4*(n-4))%mod))%mod;
        else
            return memo[n] = ((((long long)v1*(n-1))%mod)+(((long long)v3*(n-3))%mod))%mod;
    }
    int findFun(int n) {
        // code here
        vector<int> memo(n+1,-1);
        return findFun2(n,memo);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        Solution obj;
        int res = obj.findFun(n);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
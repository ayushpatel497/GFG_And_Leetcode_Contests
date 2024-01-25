//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int dfs(vector<int>&v,int a,vector<vector<int>>&dp,int i){
        if(i<0)return 0;
        int d,e=0;
        if(dp[i][a]!=-1)return dp[i][a];
        d=dfs(v,a,dp,i-1);
        if(a>=v[i]){
            e=v[i]+dfs(v,a-v[i],dp,i-1);
        }
        return dp[i][a]=max(d,e);
    }
    
    bool dd(vector<int>&v,long long a,long long b,int n,long long m,long long d){
        a*=m;
        b*=m;
        if(a>=d||b>=d)return 1;
        if(a>b)swap(a,b);
        vector<vector<int>>dp(n,vector<int>(a+1,-1));
        m=dfs(v,a,dp,n-1);
        d-=m;
        return b>=d;
    }
    
    int findMinTime(int a, int b, int n, vector<int> &v)
    {
        int m,i,s=1,e=1e5+1;
        long long d=0;
        for(i=0;i<n;i++)d+=v[i];
        while(e-s>1){
            m=(e+s)/2;
            if(dd(v,a,b,n,m,d))e=m;
            else s=m+1;
        }
        if(dd(v,a,b,n,s,d))return s;
        return e;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.findMinTime(a,b,n,arr)<<endl;
    }
}

// } Driver Code Ends
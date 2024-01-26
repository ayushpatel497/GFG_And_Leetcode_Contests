//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalCount(int n, string s) {
        // code here
        int mod=1e9+7;
        int sum=n;
        int i=0;
        for(i=1;i<n;i++)
            if(s[i]==s[0])
                sum=sum%mod+(n-i)%mod;
        return sum%mod;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        cin>>n;
        
        
        string s;
        cin>>s;

        Solution obj;
        int res = obj.totalCount(n, s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
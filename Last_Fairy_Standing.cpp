//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lastFairyStanding(int n, int k) {
        // code here
        int ans=0;
        for(int i=2;i<=n;i++)
             ans=(ans+k)%i;
        return ans+1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        int res = obj.lastFairyStanding(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
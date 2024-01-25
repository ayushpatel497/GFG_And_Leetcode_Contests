//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long numOfWays(int n)
    {
        //Write Code Here
        if(n&1) return 0;
        long k = (n-1)>>1;
        k>>=1;
        k*=6;
        return k;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.numOfWays(n)<<endl;
    }
}

// } Driver Code Ends
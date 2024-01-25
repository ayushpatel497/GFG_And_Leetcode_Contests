//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int minOPs(int n, vector<int> &A)
    {
        //Write Code Here
        unordered_map<int,int>um;
        for(auto it:A) um[it]++;
        vector<int> v;
        for(auto it:um) v.push_back(it.second);
        sort(v.begin(),v.end());
        int sum=0;
        for(int i=v.size()-1;i>=0;i--)
        {
          sum+=v[i];
          if(sum>(n/2)) return v.size()-1-i;
        }
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
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.minOPs(n,arr)<<endl;
    }
}

// } Driver Code Ends
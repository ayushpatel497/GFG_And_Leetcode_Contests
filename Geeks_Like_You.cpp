//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<int> findAnswer(int n, vector<int> &a)
    {
        vector<int>ans;
        for(int i=0;i<n;i++){
            long long sum = 0;
            int len = 0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                len++;
                if(sum>0){
                    ans.push_back(len);
                    break;
                }
            }
            if(sum<=0){
                ans.push_back(0);
            }
        }
        return ans;
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
        for(auto it:ob.findAnswer(n,arr)) cout<<it<<" ";
        cout<<endl;
    }
}

// } Driver Code Ends
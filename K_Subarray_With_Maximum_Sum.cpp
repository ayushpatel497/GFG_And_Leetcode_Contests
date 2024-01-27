//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long kMaxSubarray(int n, int k, vector<int> &arr) {
        // code here
        int l=0,r=0,sum=0,ans=INT_MIN;
        for(;r<n;r++){
            sum+=arr[r];
            if(r-l+1 > k){
                sum-=arr[l];l++;
                int curr=0;
                for(int i=l;i<r;i++){
                    curr+=arr[i];
                    if(curr<0){
                        sum-=curr; l=i+1;
                        curr=0;
                    }
                }
            }
            ans=max(ans,sum);
            if(sum<0){
                sum=0;
                l=r+1;
            }
        }
        return ans;
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
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        long long res = obj.kMaxSubarray(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
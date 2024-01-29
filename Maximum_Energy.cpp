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
    int mod=1000000007;
  public:
    int MaximumEnergy(int N, vector<int> &E, int K, vector<int> &P) {
        // code here
        int ans=0;
        vector<int>preSum(N);
        preSum[0]=E[0];
        for(int i=0;i<N;i++){
            preSum[i]=(E[i]+preSum[i-1])%mod;
        }
        sort(P.begin(),P.end());
        int i=0,j=K-1;
        while(i<j){
            ans=(ans+((preSum[P[j]]-preSum[P[i]])+E[P[i]])%mod)%mod;
            i++;
            j--;
        }
        return (ans%mod+mod)%mod;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> E(N);
        Array::input(E,N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> P(K);
        Array::input(P,K);
        
        Solution obj;
        int res = obj.MaximumEnergy(N, E, K, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends